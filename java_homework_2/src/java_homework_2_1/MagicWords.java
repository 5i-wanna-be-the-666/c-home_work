package java_homework_2_1;

import java.awt.Graphics;
import java.util.Scanner;

@SuppressWarnings("unused")
public class MagicWords {
	String s;
	IdentifyFormatter a=new IdentifyFormatter(" ");//��������ĳ�ʼ��
	UppercaseColorFormatter b=new UppercaseColorFormatter(" ");
	ROT13Formatter c=new ROT13Formatter();
	
	
	void magic()
	{
		
		Scanner scan = new Scanner(System.in);
		String l=new String();
		 System.out.println("�������ַ�����");//�����ַ���
	        if (scan.hasNextLine()) {
	          l = scan.nextLine();
	            
	        }
	        
	        
	       
		while((a.Identify(l).equals("")))//����Ƿ�ֻ������ĸ�Ϳո�
		{
			
			System.out.println("�����������������룺");
	        l = scan.nextLine();
		}
		scan.close();
		l=c.jiami(l);
		System.out.println("�����ַ�����"+l);
		l=c.jiemi(l);
		System.out.println("�����ַ�����"+l);

		b.UppercaseColor(l);//��ɫ�ĺ�������ֻ������һ�������������ɫ֮�������
	}
	 
	public static void main(String[] args){
		MagicWords w=new MagicWords();
		w.magic();
	}

}
