pragma solidity ^0.4.24;


/*
	1. msg.sender : 컨트랙트를 실행시킨 사람의 주소.
	2. setBalance 함수 실행 = msg.sender와 입력받은 input으로 [키, 데이터] 쌍을 만들어 맵핑 balances에 삽입.
*/
contract Example53
{
    mapping (address => uint) public balances;

    function setBalance(uint input)
    {
        balances[msg.sender] = input;
    }
}