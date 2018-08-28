pragma solidity ^0.4.24;
// 고정 바이트 배열

contract Example25
{
    function byteExample() public returns (byte and, byte or, byte xor, byte negation)
    {
        byte v1 = 0x00;
        byte v2 = 0xff;

        and = v1 & v2;
        or = v1 | v2;
        xor = v1 ^ v2;
        negation = ~v1;
    }
}