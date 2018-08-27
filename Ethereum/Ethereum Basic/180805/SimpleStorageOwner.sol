pragma solidity ^0.4.24;

contract SimpleStorageOwner
{
    uint public storedData;

    // 계약을 배포한 계정 주소를 저장할 owner 변수 정의
    address public owner;
    
    constructor() public
    {
        // 생성자 정의
        owner = msg.sender;
    }
    
    modifier onlyOwner()
    {
        // 생성자로 설정한 계정만 데이터 변경(거래)를 실행할 수 있게 설정.
        // 생성자가 아니면 데이터 변경 취소.
        require(msg.sender == owner);
        _;  // 함수 제한자.
    }

    // storedData 값 변경
    function set(uint x) onlyOwner public
    {
        storedData = x;
    }

    function get() onlyOwner public constant returns (uint)
    {
        return storedData;
    }
}