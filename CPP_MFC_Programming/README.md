# 1 윈도우 프로그래밍 모델

윈도우에서 message란? 모든 것이 다 msg

msg driven 방식이다.

HW에서 message가 발생 -> msg queue에 넣어짐 -> 하나씩 꺼내서 msg loop에 진입 -> winproc 함수에서 처리

GetMessage 함수가 제일 중요!
DispatchMessage함수가 호출되면 윈도우 프로시져 함수가 호출됨 winproc
