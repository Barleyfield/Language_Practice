pragma solidity ^0.4.18;

contract Example18
{
    function convertExample() public pure returns (uint32, uint16)
    {
        int8 x = -5;
        //uint32 y = uint32(x);
        // → Unused local variable 오류 출력.
        uint32 y;
        y = uint32(x);

        uint32 a = 0x12345678;
        //uint16 b = uint16(a);
        // → Unused local variable 오류 출력.
        uint16 b;
        b = uint16(a);
        
        return (y,b);
    }
}