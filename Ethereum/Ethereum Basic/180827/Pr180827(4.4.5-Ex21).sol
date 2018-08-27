pragma solidity ^0.4.24;

contract Example21
{
    uint[3] globalStaticArray = [1,2,3];
    uint[] globalDynamicArray = [1,2,3];    // 동적 배열 선언 후 초깃값 넣었음.
    uint[] globalDynamicArrayEmpty;

    function ArrayExample() public
    {
        uint[3] localStaticArray1;
        uint[4**2] localStaticArray2;   // 4의 제곱이므로 크기는 16.
        uint[] localDynamicArray = new uint[](8); //
        uint[][10] localDynamic2DimensionalArray;
    }
}