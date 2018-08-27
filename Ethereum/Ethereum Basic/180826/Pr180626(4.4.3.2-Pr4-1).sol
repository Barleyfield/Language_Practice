pragma solidity ^0.4.18;

contract Practice4
{
    int a;
    int b;
    function set_A_B(int a_input, int b_input) public
    {
        a = a_input;
        b = b_input;
    }

    function get_A_B() public returns (int, int)
    {
        (b>0) ? (a=1) : ( b<0 ? (a=0) : (a=-1) );
        return (a,b);
    }

}