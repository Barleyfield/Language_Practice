pragma solidity ^0.4.24;

// 동적 바이트 배열

contract Example4
{
    function byteExample() public
    {
        bytes2 staticByteArray;
        staticByteArray = "staticByteArray";

        bytes memory dynamicByteArray;
        dynamicByteArray = "dynamicByteArray";

    }
}