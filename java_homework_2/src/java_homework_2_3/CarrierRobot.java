package java_homework_2_3;

@SuppressWarnings("serial")
public class CarrierRobot extends AbstractRobot {

	CarrierRobot()
	{
		super();
	}
	
	CarrierRobot(String name,float a,int b,float c)
	{
		super(name,a,b,c);
	}
	void greet() //ʵ�ֵ�greet����
	{
		
		this.talk("Welcom to CarrierRobot");
		
	}
	
	void carry(float capacity)//ʵ�ֵ�carry����
	{
		if(capacity>this.weight)
		{
			System.out.println("���ع��أ������˳��ܲ���");
		}
	}
    
}
