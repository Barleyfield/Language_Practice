// 연습문제 3과 함께.
pragma solidity ^0.4.18;

contract Example4
{
    uint a;
    int b;
    bool c;
    constructor (uint _a, int _b, bool _c) public
    {
        a = _a;
        b = _b;
        c = _c;
    }

}

contract ExampleCreator
{
    Example4 e = new Example4(2017, -5, true);
}
