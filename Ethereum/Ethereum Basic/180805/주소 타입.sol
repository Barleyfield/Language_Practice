pragma solidity ^0.4.24;

contract Address
{
    function () payable public { }

    function getBalance_s(address _t) public view returns (uint)
    {
        if(_t == address(0))
        {
            _t = this;
        }
        return _t.balance;
    }

    function transfer(address _to, uint _amount) public
    {
        if(!_to.send(_amount))
        {
            revert();
        }
    }
    function send(address _to, uint _amount) public
    {
        if(!_to.send(_amount))
        {
            revert();
        }
    }


    
}