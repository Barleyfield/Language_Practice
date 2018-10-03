// 작성 날짜 : 2018-08-28
// 출처 : 이더리움 베이직

pragma solidity ^0.4.24;

contract Example
{
    // 바이트 배열과 문자열의 상호 변환
    function convertBytesToString(bytes b) public returns (string)
    {
        return string(b);
    }
    function convertStringToBytes(string str) public returns (bytes)
    {
        return bytes(str);
    }

    // bytes[]와 string 간 변환.
    function convertByteArrayToString(byte[] b) public returns (string)
    {
        // 0x57, 0x6f... → Hello
        bytes memory buffer = new bytes(b.length);
        for(uint n = 0; n<buffer.length; n++)
        {
            buffer[n] = b[n];
        }
        return string(buffer);
    }
    function convertStringToByteArray(string str) public returns (byte[])
    {
        // Hello → 0x57, 0x6f...
        bytes memory d = bytes(str);
        byte[] memory buffer = new byte[](d.length);
        for(uint i=0; i<buffer.length; i++)
        {
            buffer[i] = byte(d[i]);
        }
        return buffer;        
    }

    // 2개의 문자열 병합 함수
    function mergeStrings(string s1, string s2) public returns (string)
    {
        /*
        Java, C#이라면 + 연산으로 문자열을 병합할 수 있지만
        Solidity는 이 방식을 지원하지 않는다.
        따라서, 입력된 두 개의 문자열의 길이를 크기로 가지는 bytes형 변수를 선언한 뒤,
        string형을 bytes형으로 변환하여 입력한다.
        */
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

    // 부분 문자열 반환 함수
    function subString(string str, uint start, uint length) public returns (string)
    {
        bytes memory fullBytes = bytes(str);
        // 오류 방지 if문
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

    // 문자열을 숫자로 변환하는 함수
    // convertStringToByte 함수 필요.
    function convertStringToInt(string s) public returns (int)
    {
        bytes memory b = convertStringToBytes(s);
        int result = 0;
        uint start = 0;
        int phase = 1;      // 최종 값을 양수/음수로 만들 변수

        // 숫자가 음수/양수일 경우 대비
        if(b[0] == byte("-"))
        {
            phase = -1;     // 첫 번째 문자가 -라면 phase를 -1로.
            start = 1;
        }
        else if(b[0] == byte("+"))
        {
            start = 1;
        }

        for(uint i = 0; i<b.length; i++)
        {
            // 오류 방지 if문
            if( (b[i] < byte("0") || b[i] > byte("9")) && ( b[i] != byte("+") && b[i] != byte("-") ) )
            {
                return 0;
            }
            
            // 첫 문자가 +나 -이면 두 번째 연산부터 수행해야 하므로
            // i = start = 1로 놓았다.
            result += (int(b[i]) - 48) * int(10**(b.length - (i+1)));
        }

        result *= phase;

        return result;

    }

    // 숫자를 문자열로 변환하는 함수
    // convertBytesToString 함수 필요
    /* 
        Java, C# 등에서는 ToString()이라는 함수를 지원하여 쉽게 사용
        Solidity에서는 지원하지 않음. 직접 만들어야 한다.
    */
    function convertIntToString(int n) public returns (string)
    {
        uint length = 10;
        uint i = 0; int d; int t; int v = n;

        if(n<0) {v *= -1;}  // 음수면 -1 곱하기.

        for(uint j=1; j<=length; j++)
        {
            d = int(10**(length-j));    // d = 자릿수
            t = v % d;                  // t = 자릿수를 뺸 나머지 숫자
                                        // 예 : t = 23 = 123 % 100

            if((v-t)/d > 0)
            {
                length = (length-j + 1);
                break;
            }
        }

        // 음수일 경우
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


    // 문자열 탐색 함수
    // 문자열 2개를 입력받아 일치하는 부분이 있으면 위치 반환, 없다면 -1 반환
    function indexOf(string fullString, string subString) public returns (int)
    {
        // 전체 문자열 & 부분 문자열을 bytes로 변환
        bytes memory fullBytes = bytes(fullString);
        bytes memory subBytes = bytes(subString);
        uint same = 0;  // 일치하는 문자 수 세는 변수

        // 오류 방지용 if문
        if(fullBytes.length < 1 ||                  // 전체 문자열이 없는 경우
            subBytes.length < 1 ||                  // 부분 문자열이 없는 경우
            subBytes.length > fullBytes.length      // 부분 문자열 > 전체 문자열
        )
        { return -1; }

        for(uint i=0; i<=fullBytes.length - subBytes.length; i++)
        {
            /* 
                전체 문자열 - 부분 문자열의 길이를 뺀 만큼만 반복.
                이유 : 이후의 문자열은 볼 필요가 없기 때문.
                예 : "홍길동" 과 "길동"이라는 문자열을 입력 매개 변수로 전달
                → 부분 문자열이 2글자면 "동"까지 탐색할 필요는 없다.
            */
            if(fullBytes[i] == subBytes[0])
            {
                // 전체 문자열 i번째 = 부분 문자열 0번째라면
                // same = 1로 설정.
                same = 1;

                // for문으로 나머지 문자도 일치하는지 확인
                for(uint j=1; j<subBytes.length; j++)
                {
                    // 일치하지 않는다면 same = 0으로 초기화. break로 벗어남.
                    if(fullBytes[i+j] == subBytes[j]) { same++; }
                    else { same = 0; break; }
                }
                if(same == subBytes.length) { return int(i); }
            }
        }
        return -1;
    }
    

}
