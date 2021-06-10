; 자신과의 채팅방을 최상단에 올리기
; 자신과의 채팅방 밑의 채팅방을 클릭한 후 마우스는 카카오톡 프로그램 흰색 공간에 놓기
F6::
Loop
{
send, {AppsKey}
send, {Up}{Up}{Up}{Enter}
send, {Down}
Sleep, 50
}
return


F7::Pause
F8::ExitApp
