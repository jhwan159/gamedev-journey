#include <iostream>
#include <string>

enum class SlimeState 
{ 
    Idle, 
    Move, 
    Chase, 
    Attack, 
    Dead 
};

// TODO 1: 상태를 받아서 "정지", "이동" 같은 이름을 돌려주는 함수
//         힌트: C에서 배운 switch를 쓰면 돼요. case 앞에는 SlimeState:: 를 붙여요.
std::string toString(SlimeState s) 
{
    switch (s) 
    {
        case SlimeState::Idle: return "정지";
        case SlimeState::Move: return "이동";
        case SlimeState::Chase: return "적대적";
        case SlimeState::Attack: return "공격";
        case SlimeState::Dead: return "사망";
    }
    return "Error";
}
// TODO 2: 지금 상태와 플레이어까지의 거리를 받아서 다음 상태를 돌려주는 함수
//         기획서의 이 두 줄만 구현해봐:
//           이동,정지 --(거리 5칸 이내)--> 적대적
//           적대적    --(거리 8칸 초과)--> 이동
//         해당하는 전환이 없으면 지금 상태 그대로 돌려줘.
SlimeState next(SlimeState s, int distance) 
{
    switch (s) 
    {
        case SlimeState::Idle:
        case SlimeState::Move:
        if (distance <= 5) 
        {
            return SlimeState::Chase;
        }
        else return s;
        case SlimeState::Chase:
        if (distance > 8)
        {
            return SlimeState::Move;
        }
        else return s;
        case SlimeState::Attack:
        case SlimeState::Dead:
        return s;
    }
    return SlimeState::Idle;
}

int main() {
    SlimeState s = SlimeState::Move;
    int distances[] = {10, 9, 5,8,9};   // 플레이어가 다가왔다 멀어졌다 다시 오는 상황

    for (int d : distances) {   // C++의 범위 for문: 배열 원소를 하나씩 d에 넣어줌
        s = next(s, d);
        std::cout << "거리 " << d << " → " << toString(s) << '\n';
    }
}
