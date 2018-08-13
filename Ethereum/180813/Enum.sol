pragma solidity ^0.4.18;

contract Enum
{
    enum Tier {Bronze, Silver, Gold, Platinum, Diamond}
    
    Tier Alice = Tier.Bronze;
    Tier Bob = Tier.Gold;
    Tier Charlie = Tier.Diamond;
}
