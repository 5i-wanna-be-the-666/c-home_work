package java_homework_2_3;


import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;



@SuppressWarnings("unused")
public class RobotWorld {
	
	
	boolean RobotLegsComparator(AbstractRobot a,AbstractRobot b)//�Ƚ�numlegs
	{
		if(a.numLegs>=b.numLegs)
		return true;
		else
			return false;
		
	}
	
	boolean RobotPowerComparator(AbstractRobot a,AbstractRobot b)//�Ƚϵ���
	{
		if(a.powerLevel>=b.powerLevel)
		return true;
		else
			return false;
		
	}
    
	
	
	@SuppressWarnings("resource")
	public static void main(String []arug) throws IOException,	    
	ClassNotFoundException {
		int i=0;
		List<AbstractRobot> A=new ArrayList<AbstractRobot>();//�õ�ArrayList�洢����
		
		FileOutputStream os = new FileOutputStream("Robot.txt");//д���ļ��е����������
		ObjectOutputStream oos = new ObjectOutputStream(os);
		
		
		    
		
		
		Interface_crudRobot xx=new Interface_crudRobot();//���ǹ�������˵Ķ���
		
		AbstractRobot []Ab =new AbstractRobot[7];;//��ʼ������
		AbstractRobot C1=new CarrierRobot();
		AbstractRobot T1=new TranslationRobot();
		
		AbstractRobot C2=new CarrierRobot("f*ck",55,9,6);
		AbstractRobot T2=new TranslationRobot("think",88,2,2);
		
		AbstractRobot C3=new CarrierRobot("what",59,15,6);
		AbstractRobot T3=new TranslationRobot("talk",998,2,999);
		
		AbstractRobot C4=new CarrierRobot("wat",9,5,6);//�����ǳ�ʼ������
		
		Ab[0]=C1;
		Ab[1]=T1;
		Ab[2]=C2;
		Ab[3]=T2;
		Ab[4]=C3;
		Ab[5]=T3;
		Ab[6]=C4;//����ӳ��
		
		xx.inser(A,Ab);//xx�Ľ������������ArrayList��
		
		
		xx.find(A,C1);//��
		xx.update(A,T2,T3);//��
		xx.display(A);//��ʾ
		xx.delete(A,C1);//ɾ
		 
		for(i=0;i<Ab.length;i++)
		oos.writeObject(Ab[i]);//д���ļ���
		
		oos.flush();
	    oos.close();
	    
	    FileInputStream is = new FileInputStream("Robot.txt");//����������
	    ObjectInputStream ois = new ObjectInputStream(is);
	    i=0;
	   for(i=0;i<Ab.length;i++)//�����ļ��еĶ���
	    {
		   Ab[i].greet();
				   try {
				
				    
				    if(i%2!=0)//��Ϊ��������������Ҫ�ֿ����ۣ�����׼���ã�getclass����ȵģ�����������������
				    {
				    	TranslationRobot deserialized = (TranslationRobot) ois.readObject();
				    	System.out.println("�ļ�  "+i);
						System.out.println(deserialized.toString());
				    }
				    
				    if(i%2==0)
				    {
				    	CarrierRobot deserialized = (CarrierRobot) ois.readObject();
				    	System.out.println("�ļ�  "+i);
						System.out.println(deserialized.toString());
				    }
				   
				    
				   
				   
				}
				catch(Exception e) {//������Է�ֹ�м�������⣬ֱ�Ӷ������
					System.out.println("��ȡ���");
		            e.printStackTrace();
		        }
	    	 
	    	
	    		
	    
	    }
	    
	    

		
	}
}
