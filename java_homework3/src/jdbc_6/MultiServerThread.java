package jdbc_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

class MultiServerThread extends Thread
{	
	private Socket cs;
	private int cltNum;
	
	
	
	private Connection con;
	private final String MYSQL_USERNAME = "yourStudentID";
 	private	final String MYSQL_PASSWORD = "123456";
	
	public MultiServerThread(Socket socket, int clientNumber)
    {
		this.cs=socket;
		this.cltNum=clientNumber;		
		System.out.println("Accepted Client��" + cltNum); 
    }
	public void run()
	{		
		try{
    		//��Socket��������������������BufferedReader����
            InputStreamReader rs;
				rs = new InputStreamReader(cs.getInputStream());	//��������
            BufferedReader is=new BufferedReader(rs); 
            //��Socket�������������������PrintWriter����
            PrintWriter os = new PrintWriter(cs.getOutputStream(),true);
            
          //��Socket�ж�������Client�����ݲ��������Ļ
           
            String []s=new String[3];
            
            int i;
            	
            for(i=0;i<3;i++)
            {
            	 String line = is.readLine();
 	            System.out.println("Client msg is:"+line);
 	            s[i]=line;
 	          
 	            
            }
            os.println("����������");
            
           
            try {
				Class.forName("com.mysql.cj.jdbc.Driver");
				
				String url = "jdbc:mysql://localhost:3306/myUniversity?useSSL=false&serverTimezone=UTC";
				con = DriverManager.getConnection(url, MYSQL_USERNAME, MYSQL_PASSWORD);
				Statement st = con.createStatement();
				String sp="INSERT INTO metropolises(metropolis,continent,population) VALUES("+"'"+s[0]+"'"+","+"'"+s[1]+"'"+","+"'"+s[2]+"'"+")";
				 st.executeUpdate(sp);
				 os.println("��������ݳɹ�");
		        System.out.println("��������ݳɹ�");
		        
			} catch (SQLException e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			} catch (ClassNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
            
				
			 //����ѭ��
            is.close(); //�ر�������
            os.close(); //�ر������
            cs.close(); //��һ���ͻ�ͨ����ϣ��ر�Client socket
            
		}catch (IOException ie) {
			ie.printStackTrace();
		}
           
	}//end of run
		
   }


