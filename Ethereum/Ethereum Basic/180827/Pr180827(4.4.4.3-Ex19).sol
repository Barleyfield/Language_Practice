pragma solidity ^0.4.18;

contract Example19
{
    function conversionExample() public pure returns (uint)
    {
        uint32 a = 0x12345678;
        var b = a;
        var c = 1;
        for(var i=0; i<1234; i++)
        {
            // 무한루프. i가 uint8 타입이라 항상 1234보다 작기 때문.
        }
    }
}