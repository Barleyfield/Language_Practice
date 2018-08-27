pragma solidity ^0.4.24;

contract Example20
{
    uint[3] myArray1;
    uint[3] myArray2 = [0,1,2];
    uint[3] myArray3;
    uint[3] myArray4;


    function Example20_array() public
    {
        myArray1[0] = 0;
        myArray1[1] = 1;
        myArray1[2] = 2;

        for(uint8 i=0; i<3; i++)
        {
            myArray3[i] = i;
        }
        for(uint8 j=0; j<3; j++)
        {
            myArray4[j] = myArray3[j];
        }
    }
}