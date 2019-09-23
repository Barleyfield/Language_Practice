/*!
\file CppTest.cpp
C++ 문법과 DoxyGen 문법을 테스트하기 위한 코드
 */
#include "stdafx.h"
#include <iostream>
#include <conio.h> ///< getch() 함수를 사용하기 위해서 포함되었다.

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*!
\mainpage C++ & DoxyGen 문법 테스트
C++과 독시젠 문법을테스트하기 위한 정보
\section intro_sec Introduction
This is the introduction.
\section install_sec Installation
\subsection step1 Step 1: Opening the box
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///\page page1 A documentation page
///\tableofcontents
/// Leading text.
///\section sec An example section
/// This page contains the subsections \ref subsection1 and \ref subsection2.
/// For more info see page \ref page2.
///\subsection subsection1 The first subsection
/// Text.
///\subsection subsection2 The second subsection
/// More text.

///\defgroup ROOT_INIT Root* 클래스를 초기화 하는 함수들
///
///\defgroup VIRTUAL_TEST virtual 기능을 테스트 하기 위한 함수들
///
///\defgroup GLOBAL_FUNC 클래스에 속하지 않는 외부 함수들
///
///\defgroup OUT_GRP_TEST 외부 그룹에 속하는 함수 테스트
///

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*! \page page2 Another page
  Even more info.
*/

///\var static int _varG
///\brief 스태틱 상태값
static int _varG = 0;

//class SalesPromotionInfo CommonDataJP.h "XDORA/CommonData.h"
///\brief
/// 세일즈 프로모션 데이터를 저장하는 구조체.
///\details	XDoraJPSelectSalesPromotion1 쿼리를 사용해서 현재 DB에 설정되어 있는 SP 목록을 받아온다. 
class SalesPromotionInfo
{
public:
	LONGLONG	llSeq;	///< 일련번호. 단순한 인덱스.
	int			nOrders;	///< 우선 순위. 표시할때 쓰려나. 어디한번 자세하게 쓰면 어떻게 나오려나?
	char		szSPType[5 + 1];	///< SP의 종류. (미정)
	char		szStartDate[22 + 1];	///< 시작 날짜
	char		szEndDate[22 + 1];	///< 종료 날짜
	char		szTitle[100 + 1];	///< 제목
	char		szContent[1000 + 1]; ///< 설명
	char		szImgUrl[512 + 1];	///< 참고 배너
	char		szMoveTo[5 + 1];	///< 클릭시 이동할 곳 (미리 정의 된 곳이 필요합니다.)
	int			nDeviceType;	///< 디바이스 구분이 필요한가? (0:all, 1:ios, 2:android)
};

///\brief 최상단 루트 클래스
///\ingroup VIRTUAL_TEST
class RootZero
{
public:
	///\brief 소멸자 클래스로, 함수 이름을 출력하고 종료한다.
	virtual ~RootZero()
	{
		cout << __FUNCTION__ << endl;
	}
	///\brief virtual 기능 확인용 테스트 함수.
	/// child 클래스에서만 사용하도록 virtual pure 로 선언된다. 
	///\ingroup ROOT_INIT 
	virtual bool initHandler() = 0;
};

///\class RootOne
///\brief RootZero로 부터 상속된 테스트 클래스 2
///\ingroup VIRTUAL_TEST
class RootOne : public RootZero
{
public:
	RootOne()
	{
		cout << __FUNCTION__ << endl;
	}

	virtual ~RootOne()
	{
		cout << __FUNCTION__ << endl;
	}

	///\brief
	///\ virtual 기능 확인용 테스트 함수. 함수 이름을 출력하고 종료한다.
	///\ingroup ROOT_INIT
	virtual bool initHandler()
	{
		cout << __FUNCTION__ << endl;
		return true;
	}

	int mnTest; ///< 테스트용 인티져값
};

///\brief RootOne로 부터 상속된 테스트 클래스 3
///\ingroup VIRTUAL_TEST
class RootTwo : public RootOne
{
public:
	RootTwo()
	{
		cout << __FUNCTION__ << endl;
	}
	virtual ~RootTwo()
	{
		cout << __FUNCTION__ << endl;
	}

	///\brief virtual 기능 확인용 테스트 함수. 
	/// 부모 클래스의 같은 함수를 실행하고 그 뒤에 함수 이름을 출력하고 종료한다.
	///\ingroup ROOT_INIT 
	virtual bool initHandler()
	{
		if( ! __super::initHandler() ) return false;
		cout << __FUNCTION__ << endl;
		return true;
	}
};

///\brief RootTwo로 부터 상속된 테스트 클래스 4
///\ingroup VIRTUAL_TEST
class RootThree : public RootTwo
{
public:

	///\brief CommonLobbyJP를 위해서 사용될 콜백 함수
	typedef bool (__stdcall *TPacketRecvFromMRS)(IN RootThree*, IN void*);

	RootThree()
	{
		cout << __FUNCTION__ << endl;
	}
	virtual ~RootThree()
	{
		cout << __FUNCTION__ << endl;
	}

	///\brief virtual 기능 확인용 테스트 함수. 
	/// 부모 클래스의 같은 함수를 실행하고 그 뒤에 함수 이름을 출력하고 종료한다.
	///\ingroup ROOT_INIT 
	virtual bool initHandler()
	{
		if( ! __super::initHandler() ) return false;
		cout << __FUNCTION__ << endl;
		return true;
	}

	///\ingroup OUT_GRP_TEST 
	int Grp1() {}
	int Grp2() {}

	///\defgroup DOXY_MEMBER_GROUP 독시젠 그룹핑 테스트
	///@{
	void Grp3() {}
	void Grp4() {}
	///@}

	int mnABC; ///< abc int 변수
	int mnDEF; ///< a var in group OUT_GRP_TEST

	///\brief 독시젠에서 함수 설명이 제대로 만들어지는지 확인하기 위한 함수.
	///\details 'more'를 누르면 보여지는 설명.
	///\param[in] aa 입력용 숫자값
	///\param[in] bb 입력용 char 값
	///\param[out] dd 출력용 버퍼
	///\return 리턴용 값에 대한 설명
	///\retval -1 실패
	///\retval 0 성공
	///\retval 1 성공+뭔가 더
	///\bug 이 함수에서 가끔 뻗는데 아직 이유를 모른다.
	///\warning 이 함수에서 가끔 뻗는데 아직 이유를 모른다.
	///\see OUT_GRP_TEST
	///\ref page2
	int DoxyFuncTest( int aa, char bb, char* dd );

	/*!
	\fn int DoxyFuncTest2( int aa, char bb, char* dd )
	\brief 독시젠에서 함수 설명이 제대로 만들어지는지 확인하기 위한 함수.
	\details 'more'를 누르면 보여지는 설명. \\fn 은 함수 위에 주석을 달지 않을때 쓰는 기능.
	\param[in] aa 입력용 숫자값
	\param[in] bb 입력용 char 값
	\param[out] dd 출력용 버퍼
	\return 리턴용 값에 대한 설명
	\retval -1 실패
	\retval 0 성공
	\retval 1 성공+뭔가 더
	\bug 이 함수에서 가끔 뻗는데 아직 이유를 모른다.
	\warning 이 함수에서 가끔 뻗는데 아직 이유를 모른다.
	\see OUT_GRP_TEST
	\ref page2
	\example
		이 함수의 예제.
		char _buf[100];
		DoxyFuncTest2( 1, 'a', _buf );
	*/
	int DoxyFuncTest2( int aa, char bb, char* dd );
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///\brief Root계열 클래스를 생성한다. 그리고 리턴.
///\return RootZero* 타입으로 생성된 포인터를 리턴한다.
RootZero* getRootClassPtr()
{
	return new RootThree;
}

/*!
\brief cpp 문법 테스트.
	if() 괄호 안에 변수를 선언해도 되는가?
\param[in] param_ (> 0) 그냥 실행, (< 0) param_을 그대로 리턴.
*/
int testFunction( int param_ )
{
	if( param_ < 0 ) return param_;
	///< 아쉽게도 if( (int _vv = testFunction(-5)) < 0 ).. 는 안됐다.
	int _vv;
	if( (_vv = testFunction(-5)) < 0 )
	{
		cout << "test val: " << _vv << endl;
	}
	return param_;
}

///\brief
/// 프로그램 시작 지점 & \\brief에 대한 테스트
///\param[in] argc 실행시 넘겨지는 파라미터의 개숫
///\param[in] argv 실행시 넘겨지는 파라미터 문자열 리스트
///\return 프로그램의 실행 결과값.
///\warning 워닝 경고문 테스트
///\ingroup GLOBAL_FUNC
int _tmain(int argc, _TCHAR* argv[])
{
	testFunction(1); _getch();

	RootZero* _ptr = getRootClassPtr();
	_ptr->initHandler();
	_getch();

	delete _ptr;
	_getch();

	

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*!
\page QAOjisang QAOjisang 설정 정보 (ini)

\section 기본
기본 ini 파일명
- qaojisang.ini

설명
- 테스트용 설정을 보관하는 ini 파일
- 실제 서버용은 아니고, ini 파일 내용을 상시 변경해서 사용할 수
있도록 모든 함수들이 실행될때 ini 파일을 읽도록 했다.

\section QAOjisang ini 설정 정보
FixedFishID 테스트용으로 임의 설정할 물고기 아이디.

- FixedFishID = {숫자}

~~~~
; 사용 예
FixedFishID = 3
~~~~

에러 처리는 하지 않기 때문에 물고기 ID를 넣을때 주의가 필요.

~~~~{.cpp}
{
	// 샘플 코드가 필요하면 이렇게 넣을 수 있다.
	for( int i = 0; i < abc; )
	{
	}
}
~~~~

코드 끝. 끝부부분을 잘라버리기 때문에 뭐라도 써주는 것이 좋을 것 같다.
*/