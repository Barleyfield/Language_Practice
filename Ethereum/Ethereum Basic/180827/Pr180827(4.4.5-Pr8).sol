pragma solidity ^0.4.24;
// 8-1, 8-2 합침. 크기 100인 배열 만들고 합 구하기.

contract Practice_8
{
    
    uint[100] array;
    uint result = 0;
    function stock() public
    {
        for(uint8 i=0; i<100; i++)
        {
            array[i] = i+1;
            result += array[i];
        }
    }
    function getResult() public returns (uint)
    {
        return result;
    }
}