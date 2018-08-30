pragma solidity ^0.4.24;

contract Practice10
{


    function convertBytesToString(bytes b) public returns (string)
    {
        return string(b);
    }
    function convertStringToBytes(string str) public returns (bytes)
    {
        return bytes(str);
    }

    function convertByteArrayToString(byte[] b) public returns (string)
    {
        bytes memory buffer = new bytes(b.length);
        for(uint n = 0; n<buffer.length; n++)
        {
            buffer[n] = b[n];
        }
        return string(buffer);
    }

    function convertStringToByteArray(string str) public returns (byte[])
    {
        bytes memory d = bytes(str);
        byte[] memory buffer = new byte[](d.length);
        for(uint i=0; i<buffer.length; i++)
        {
            buffer[i] = byte(d[i]);
        }
        return buffer;        
    }

    function mergeStrings(string s1, string s2) public returns (string)
    {
        bytes memory d1 = bytes(s1);
        bytes memory d2 = bytes(s2);
        bytes memory result = new bytes(d1.length + d2.length);
        for(uint n=0; n<d1.length; n++)
        {
            result[n] = d1[n];
            
        }
        uint i = d1.length;
        for(n=0; n<d2.length; n++)
        {
            result[i + n] = d2[n];
        }

        return string(result);
    }

    function subString(string str, uint start, uint length) public returns (string)
    {
        bytes memory fullBytes = bytes(str);
        if(start + length > fullBytes.length)
        {
            return str;
        }
        bytes memory result = new bytes(length);
        for(uint i=0; i<length; i++)
        {
            result[i] = fullBytes[start + i];
        }
        return string(result);
    }

    function convertStringToInt(string s) public returns (int)
    {
        bytes memory b = convertStringToBytes(s);
        int result = 0;
        uint start = 0;
        int phase = 1;

        if(b[0] == byte("-"))
        {
            phase = -1; 
            start = 1;
        }
        else if(b[0] == byte("+"))
        {
            start = 1;
        }
        for(uint i = 0; i<b.length; i++)
        {
            if( (b[i] < byte("0") || b[i] > byte("9")) && ( b[i] != byte("+") && b[i] != byte("-") ) )
            {
                return 0;
            }
            result += (int(b[i]) - 48) * int(10**(b.length - (i+1)));
        }
        result *= phase;
        return result;
    }

    function convertIntToString(int n) public returns (string)
    {
        uint length = 10;
        uint i = 0; int d; int t; int v = n;

        if(n<0) {v *= -1;}

        for(uint j=1; j<=length; j++)
        {
            d = int(10**(length-j));    
            t = v % d;                
            if((v-t)/d > 0)
            {
                length = (length-j + 1);
                break;
            }
        }
        bytes memory buffer;
        if(n<0)
        {
            buffer = new bytes(length + 1);
            buffer[i] = byte("-");
            i = 1;
        }
        else
        {
            buffer = new bytes(length);
        }
        for(j=1; j<=length; j++)
        {
            d = int(10**(length - j));
            t = v % d;
            if((v-t)/d > 0)
            {
                buffer[i] = byte(((v-t)/d) + 48);
                v -= ((v-t)/d) * int(10**(length-j));
                i++;
            }
        }
        return convertBytesToString(buffer);
    }

    function indexOf(string fullString, string subString) public returns (int)
    {
        bytes memory fullBytes = bytes(fullString);
        bytes memory subBytes = bytes(subString);
        uint same = 0;
        if(fullBytes.length < 1 || subBytes.length < 1 || subBytes.length > fullBytes.length)
        { return -1; }

        for(uint i=0; i<=fullBytes.length - subBytes.length; i++)
        {
            if(fullBytes[i] == subBytes[0])
            {
                same = 1;
                for(uint j=1; j<subBytes.length; j++)
                {
                    if(fullBytes[i+j] == subBytes[j]) { same++; }
                    else { same = 0; break; }
                }
                if(same == subBytes.length) { return int(i); }
            }
        }
        return -1;
    }

    function 
}