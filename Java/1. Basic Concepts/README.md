# 숫자와 문자

<br/>

### 숫자
	
* 자바에서는 따옴표가 없는 숫자는 숫자로 인식한다.
  * ```System.out.println(1+2);``` 결과: 3
  * ```System.out.println(1.2+1.3);``` 결과: 2.5
  * ```System.out.println(2*5);``` 결과: 10
  * ```System.out.println(6/2);``` 결과: 3

* 문자와 문자열
	* 자바는 문자(Character)와 문자열(String)을 구분한다. 문자는 한 글자를 의미하고, 문자열은 여러 개의 문자가 결합한 것을 의미한다. 자바에서 문자는 '(작은따옴표)로 감싸야 한다. ```System.out.println('생');```
	* 문자열은 "(큰따옴표)로 감싸야 한다. ```System.out.println("생활코딩");```
	* 만약 문자열을 작은 따옴표로 감싸면 에러가 발생한다.
	* 하나의 문자를 큰따옴표로 감싼다고 에러가 발생하지는 않는다. 한 글자도 문자열이 될 수 있기 때문이다.
	
* 이스케이프
	* ```System.out.println("egoing said \"Welcome programming world\"");```
	* \를 " 앞에 위치시키면 " 를 문자열의 시작과 끝을 구분하는 구분자가 아니라 단순히 문자로 해석하도록 강제할 수 있다. 이러한 기법을 escape(이스케이프)라고 한다. 즉 큰따옴표가 가진 문법적인 역할에서 도망(escape)쳐서 문자로 인식하도록 한다는 의미다.

* 여러 줄의 표시
	* 여러 줄을 표시하고 싶을 때는 아래와 같이 하면 된다. ```System.out.println("HTML\nCSS\nJavaScript\n");```

* 문자의 연산
	* 문자와 문자를 더할 때는 아래와 같이 한다. ```System.out.println("생활"+"코딩");``` 결과: 생활코딩




# 변수

### 변수의 선언과 할당

* 정수
```
int a;
a = 1;
System.out.println(a+1); //2 
a = 2;
System.out.println(a+1); //3
```
 
* 실수
```	
double a = 1.1; 
System.out.println(a+1.1); // 2.2
a = 2.1; 
System.out.println(a+1.1); // 3.2
```


* 문자열
```	
String first = "coding"; 
System.out.println(first+" "+"everybody");
```

# Java의 데이터 타입

* 정수형
```
데이터 타입, 메모리의 크기, 표현 가능 범위 순
byte,       1 byte,      -128 ~ 127
short,      2 byte,      -32,768 ~ 32,767
int,        4 byte,      -2,147,483,648~2,147,483,647
long,       8 byte,      -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
```

* 실수형
	* float, 4byte, ±(1.40129846432481707e-45 ~ 3.40282346638528860e+38)
	* double, 8byte, ±(4.94065645841246544e-324d ~ 1.79769313486231570e+308d)
	* 실수형은 float과 double이 있다. 실수를 사용할 때는 double을 사용하도록 하자.

* 문자
	* char, 2byte, 모든 유니코드 문자

* 실수의 표현
	* 2.2의 데이터 타입은 무엇일까? float일까? double일까?
	* ```float a = 2.2; -> "Type mismatch: cannot convert from double to float"```
	* 위와 같은 에러가 발생한다. 즉 2.2는 float가 아니라는 뜻이다. 예제를 조금 바꿔보자. ```double a = 2.2;```
	* 오류가 사라졌다. 자바에서 실수형 상수는 double의 데이터 타입이다. 그럼 float 형 변수에는 어떻게 값을 대입할 수 있나? 2.2가 float 형이라는 것을 분명하게 명시해주면 된다. ```float a = 2.2F;``` F는 이 기호 앞의 숫자가 float 데이터 타입이라는 것을 명시적으로 표현하는 방법이다.

* 정수의 표현
	* 그럼 데이터 타입이 정수인 상수는 어떤 데이터 타입이 될까? int다. 이 예제는 오류가 발생할 것이다. ```int a = 2147483648;``` int의 최댓값인 2147483647 보다 1 많기 때문이다.
	* ```long a = 2147483648;, "The literal 2147483648 of type int is out of range"```
	* 변수는 long 타입이지만 이 변수에 대입되는 상수가 여전히 int 타입이기 때문에 int로 표현할 수 있는 최대 숫자를 여전히 초과하고 있다. 아래와 같이 코드를 변경해보자. ``` long a = 2147483648L;``` 이제 오류가 해결되었다. 상수도 long 타입이 되었고, 그 상수를 담을 변수도 long 타입이 되었다. 
	* 그럼 int 보다 작은 데이터 타입인 short나 byte는 어떻게 해야 표현할 수 있을까? ```byte a = 100; short b = 200;``` 이번에는 오류가 발생하지 않는다. 자바는 byte와 short 타입에 대해서는 int 형을 허용하기 때문에 오류가 발생하지 않는다.


# 형 변환

C언어와 같은 형 변환 규칙을 따른다.
[Confused C Concepts]() 참고

# 연산자

C언어와 같은 형 변환 규칙을 따른다.


# 비교와 Boolean

* .equals
	* .equals는 문자열을 비교할 때 사용하는 메소드다.
```	
package org.opentutorials.javatutorials.compare;
public class EqualStringDemo 
{ 
    public static void main(String[] args) 
	{
        	String a = "Hello world";
        	String b = new String("Hello world");
        	System.out.println(a == b); 
        	System.out.println(a.equals(b));
		// output: flase true
  	}
 
}
```
변수 a와 b에 각각 문자열을 생성해서 저장했다. 변수 b에 문자열을 만드는 방법은 생성자를 이용. 결과는 false와 true이다. ==은 두개의 데이터 타입이 동일한 객체인지를 알아내기 위해서 사용하는 연산자이기 때문에 b에 담긴 객체와 일치하지 않는 것이다. 이를 보안하는 비교 방법이 equals이고 이를 이용해서 서로 다른 객체들간에 값이 같은지를 비교할 수 있다. 문자와 문자를 비교할 때는 '=='를 사용하지 않고 .equals를 사용한다.


# 조건문

C언어와 같은 조건문 규칙을 따른다.

# 논리 연산자

C언어와 논리 연산자 규칙을 따른다.

# 반복문

C언어와 같은 규칙을 따른다.

# 배열
* Java에서 배열의 생성
```	 
public class DefineDemo 
{ 
    public static void main(String[] args) 
	{
        	String[] classGroup = { "최진혁", "최유빈", "한이람", "이고잉" };
    	}
}
String[] classGroup에서 classGroup은 배열이 담길 변수의 이름이다. String[]은 classGroup에 담을 배열에 담길 데이터의 타입이 문자열의 배열이라는 의미다. 배열을 선언할 때는 데이터 타입 뒤에 []를 붙여야 한다. []가 없다면 classGroup는 배열이 아니라 문자열 데이터 타입을 갖는 변수가 된다. 배열에 소속될 데이터들은 중괄호 안에 위치한다. 그리고 각각의 데이터들은 쉼표로 구분된다.
```

* 배열의 크기
```
public class LengthDemo 
{ 
	public static void main(String[] args) 
	{
        	String[] classGroup = new String[4];
        	// 초기화 부분은 생략.
		System.out.println(classGroup.length);
    }
}
// output: 4
```

* 더욱더 간편한 for 문
	* 배열의 내용을 탐색할 때 for 문을 좀 더 간편하게 사용할 수 있는 방법이 있다.
```
public class ForeachDemo 
{ 
	public static void main(String[] args) 
	{
        	String[] members = { "최진혁", "최유빈", "한이람" };
        	for (String e : members) 
		{
            		System.out.println(e + "이 상담을 받았습니다");
        	}
    	} 
}
for(String e : members)
위의 구문은 배열 members의 값을 변수 e에 담아서 중괄호 구간 안으로 전달해준다. 반복문의 종료조건이나 종료조건을 위해서 기준값을 증가시키는 등의 반복적인 작업을 내부적으로 감춘 것이라고 할 수 있다. 자바 5.0부터 도입된 기능이다.
```
