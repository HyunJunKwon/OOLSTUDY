# method
* 메소드나 객체지향과 같은 개념들은 웅장하고, 결함이 없고, 유지보수가 쉬운 애플리케이션을 만들기 위한 기법들이라고 할 수 있다. 이것들 없이도 프로그램을 만들 수는 있지만, 이것들 없이 규모있는 애플리케이션을 만든다는 것은 현실적으로 어려운 일이다. 지금까지 만드는 방법을 배웠다면 이제부터는 잘 만드는 방법을 익히는 것이라고 해도 과언이 아니다.

### method

* 메소드(method)는 코드를 재사용할 수 있게 해준다.

* 메소드의 형식
	* 우리는 이미 메소드를 만들고 사용했다. ```public static void main(String[] args) { return }``` 이것이 메소드다. 지금까지 수없이 만들었던 저 main이라고 하는 것이 바로 메소드인 것이다.

* 메소드의 정의와 호출
  * 아래의 예제를 보자.
```
public class MethodDemo1 
{
	public static void numbering() 
	{
        	int i = 0;
        	while (i < 10) 
		{
            		System.out.println(i);
            		i++;
        	}
    	}
	public static void main(String[] args) 
	{
        	numbering();
    	}
}

결과는 아래와 같다.	
0
1
2
3
4
5
6
7
8
9
```


* main
	* main 메소드는 규칙이다. 우리는 main 메소드를 작성하고, 자바는 main 메소드를 실행하는 관계라고 할 수 있다.

* 매개변수와 인자
	* 메소드의 입력 값은 매개변수(parameter)를 통해서 이루어진다.
``` 
public class MethodDemo4 
{
	public static void numbering(int limit) 
	{
        	int i = 0;
        	while (i < limit) 
		{
           		System.out.println(i);
            		i++;
        	}
    	}
    	public static void main(String[] args) 
	{
        	numbering(5);
    	}
}
```

* 복수의 인자
```
public class MethodDemo5 
	{ 
		public static void numbering(int init, int limit) 
		{
        		int i = init;
        		while (i < limit) 
			{
            			System.out.println(i);
            			i++;
        		}
    		}
    		public static void main(String[] args) 
		{
        		numbering(1, 5);
    		} 
}
```


* return
```
public class MethodDemo6 
{
	public static String numbering(int init, int limit) 
	{
        	int i = init;
        	// 만들어지는 숫자들을 output이라는 변수에 담기 위해서 변수에 빈 값을 주었다.
        	String output = "";
        	while (i < limit) 
		{
            		// 숫자를 화면에 출력하는 대신 변수 output에 담았다.
            		output += i;
            		i++;
        	}
        	// 중요!!! output에 담겨 있는 문자열을 메소드 외부로 반환하려면 아래와 같이 return 키워드 뒤에 반환하려는 값을 배치하면 된다.
        	return output;
    	}
    	public static void main(String[] args) 
	{
        	// 메소드 numbering이 리턴한 값이 변수 result에 담긴다.
        	String result = numbering(1, 5);
        	// 변수 result의 값을 화면에 출력한다.
        	System.out.println(result);
    	}
}
```

* 복수의 리턴

```
public class ReturnDemo3 
{
	public static String getMember1() 
	{
        	return "최진혁";
    	}
    	public static String getMember2() 
	{
        	return "최유빈";
    	}
    	public static String getMember3() 
	{
        	return "한이람";
    	}
    	public static void main(String[] args) 
	{
        	System.out.println(getMember1());
        	System.out.println(getMember2());
        	System.out.println(getMember3());
    	}
}
하나의 메소드는 하나의 값만을 반환할 수 있기 때문에 위와 같이 각각의 회원정보를 반환하는 메소드를 만들었다. 무언가 비정상적이지 않은가? 이번엔 배열을 이용한 아래의 코드를 보자. 맴버를 담고 있는 배열을 반환하고 있다. 메소드 getMembers가 리턴한 배열을 members 변수에 담았다. 이 변수를 이용해서 여러 개의 데이터를 처리 할 수 있게 된다.

public class ReturnDemo4 
{ 
	public static String[] getMembers() 
	{
        	String[] members = { "최진혁", "최유빈", "한이람" };
        	return members;
    	}
    	public static void main(String[] args) 
	{
        	String[] members = getMembers();
    	}
}
```
