// for문에서 증가식 수정 → 1~1000 중 2의 배수만 합산
pragma solidity ^0.4.18;

contract Practice_5_1
{
    function Sum() public pure returns (int)
    {
        int result = 0;

        for(int i=1; i<=1000; i++)
        {
            if(i%2 == 0)
            {
                result += i;
            }
        }

        return result;

    }
    
}