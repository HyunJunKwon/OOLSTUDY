# Inpu and Output

### String[] args
```
class InputDemo
{
	public static void main(String[] args)
	{
        	System.out.println(args.length);
    	}
}
```
* main 메소드는 자바에서 특별한 의미를 가진 메소드다. main 메소드의 내용을 구현하면 자바 에플리케이션을 실행할 때 main 메소드가 호출되면서 프로그램이 구동하게 되는 것이다. 이 때 Strings[] args는 입력 값의 파라미터로 동작한다.
String[] args은 매개변수다. 매개변수는 메소드가 호출될 때 전달된 입력 값을 메소드 내부로 전달하는 역할을 하는 변수다. 이 변수의 데이터형은 String[]인데, String[]은 문자열을 담고 있는 배열이다. args.length는 배열의 길이를 의미한다.
```
위의 코드를 실행시켜 보면,
javac InputDemo.java
java InputDemo 1 2 3 4 5 6;
=> 6
java InputDemo one two three;
=> 3 
```

* 앱이 실행중에 입력 받기
	* 자바앱이 실행되고 있는 동안에 사용자의 입력을 받는 법을 알아보자. 자바에서 기본적으로 제공하는 라이브러리 중에 scanner을 이용하면 쉽게 사용자의 입력을 잡을 수 있다. 
``` 
import java.util.Scanner;
public class ScannerDemo 
{ 
	public static void main(String[] args) 
	{
        	Scanner sc = new Scanner(System.in);
        	int i = sc.nextInt();
        	System.out.println(i*1000);
        	sc.close();
    	}
}
```
  * 위의 예제를 실행하고 숫자를 입력하면 입력한 숫자의 1000배가 출력 될 것이다. 
  * 우리가 주목해야 할 부분은 sc.nextInt()가 실행되면 자바는 사용자의 입력이 있을 때까지 변수 i에 값을 할당하지 않고 대기상태에 있게 된다. 
  * 키보드로 데이터를 입력하고 엔터를 누르면 비로서 i에 값이 담기고 i*1000을 통해서 입력값에 1000이 곱해지고 그 결과가 화면에 출력된다. 

* 아래의 코드는 연속적으로 값을 입력 할 수 있고, 입력한 값에 1000을 곱한 결과를 출력하는 예제다.
```
import java.util.Scanner; 
public class Scanner2Demo 
{
	public static void main(String[] args) 
	{
        	Scanner sc = new Scanner(System.in);
        	while(sc.hasNextInt()) 
		{
            		System.out.println(sc.nextInt()*1000); 
        	}
        	sc.close();
    	} 
}
```
* sc.hasNextInt()는 입력값이 생기기 전까지 실행을 유보시키는 역할을 한다. 만약 입력한 값이 int 형이 아닐 경우는 false를 리턴하고, int로 표현할 수 있는 형식의 숫자형인 경우는 true를 리턴한다. 따라서 위의 코드는 사용자가 입력을 할 때가지 실행을 기다렸다가 입력이 일어나면 반복문이 동작하면서 입력값의 1000배를 곱한 수가 출력된다. 

* 여러형태의 입출력
	* 사용자의 키보드 제어만이 입력은 아니다. 아래 예제는 out.txt라는 파일을 입력 받아서 화면에 출력하는 예를 보여주고 있다. 예제를 실행하려면 프로젝트의 루트 디렉토리(src와 bin 디렉토리가 위치하고 있는 경로)로 이동해서 아래와 같이 명령을 실행한다. out.txt 파일이 존재해야 한다.
``` 
import java.util.Scanner;
import java.io.*; 
public class Scanner3Demo 
{ 
	public static void main(String[] args) 
	{
		try 
		{
            		File file = new File("out.txt");
            		Scanner sc = new Scanner(file);
            		while(sc.hasNextInt()) 
			{
                		System.out.println(sc.nextInt()*1000); 
            		}
            		sc.close();
        	} 
		catch(FileNotFoundException e)
		{
            		e.printStackTrace();
        	} 
    	}
}

결과는 파일의 내용이 무엇인가에 따라서 달라질 것이다. 이 또한 분명한 입력값이다. 프로그램으로 유입되는 모든 정보는 입력값이다.
```

* GUI
	* 물론 입력이나 출력이 꼭 텍스트여야 하는 것은 아니다. 다음 URL에 담겨있는 코드는 자바를 이용해서 그래픽컬한 사용자 조작 수단을 만드는 방법을 보여준다. [Java Tutorials Code Sample - DialogDemo.java](https://docs.oracle.com/javase/tutorial/displayCode.html?code=http://docs.oracle.com/javase/tutorial/uiswing/examples/components/DialogDemoProject/src/components/DialogDemo.java) (Java Web Start가 필요하다)


* 이클립스에서 입력 값 사용하기
	* 파일을 선택하고 Run Configuration을 선택한다. Arguments 탭에서 Program Arguments에 입력 값을 작성하면 콘솔에서 입력 값을 전달하는 것처럼 할 수 있다. 
