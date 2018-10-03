pragma solidity ^0.4.24;

contract Example24 {
    uint32[3] globalStaticArray = [1,2,3];
    uint8[] globalDynamicArray = new uint8[](7);
    uint256[3] globalErrorArray = [1234, 5678, 9012];

    function arrayExample() {
        // memory 배열로 수정
        uint8[3] memory localStaticArray = [1,2,3];
        uint8[] memory localErrorArray = new uint8[] (localStaticArray.length);

        /* 잘못된 코드
        uint8[3] localStaticArray = [1,2,3];
        uint8[3] localErrorArray = new uint8[](localStaticArray.length);
        */
        uint8[] localDynamicArray = globalDynamicArray;

    }
}