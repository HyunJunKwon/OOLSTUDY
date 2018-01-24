# Java

<br/>

* 이 개념 정리는 [생활코딩](https://opentutorials.org/course/1223)을 참고하였다.
* 또한 A ~ Z의 개념정리가 아닌 C, C++와 다른 Java 특유의 문법만을 정리해 놓았다.


### Java의 역사
* 1995년 자바의 아버지라고 불리는 제임스 고슬링과 그의 동료들에 의해서 시작된 프로젝트다. Java는 원래 가전제품을 제어하기 위한 언어로 고안되었지만 웹의 등장으로 엄청난 성공을 거두면서 주류 언어가 되었다. 


### 이클립스의 기능과 예제의 사용법
* File>New->Java Project 선택 후, Project name 설정 후 Location 선택, finish
* Project Exploer의 project에서 우클릭 후, new에서 package 선택 (package는 디렉토리의 의미와 같다), package name 설정한다. 생성 된 package에서 우 클릭 후, class를 생성한다(밑에 public static void main(String[] args) 선택).
```
package JavaStudyPackage;

public class Study {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("HI");
	}

}
```
