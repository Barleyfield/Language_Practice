// -1~-1000 합 구하기

pragma solidity ^0.4.18;

contract Practice_5_2
{
    function getResult() public pure returns (int)
    {
        int result = 0;

        for(int i=1; i<=1000; i++)
        {
            result -= i;
        }
        return result;
    }
}