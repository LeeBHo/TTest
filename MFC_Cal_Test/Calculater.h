#include "MFC_Cal_TestDlg.h"
#include "Resource.h"
//Calculater�� ���� ���� ����



class Calculater_LBH :public CMFC_Cal_TestDlg
{
	DECLARE_DYNAMIC(Calculater_LBH);

private:
char m_operater_flag = 0; //plus:0/minus:1/mut:2/divi:3
char m_step = 0;		//������ Ȯ�κ���
int m_count = 0;		// ������ ī��Ʈ ����
double m_value = 0;     // ���ڰ��� �����ϱ� ���� ����
double m_flant = 0;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
//void M_Operate(double m_value_two);
	Calculater_LBH(CWnd* pParent = NULL);
	virtual ~Calculater_LBH();

public:	
	enum { IDD = IDD_MFC_CAL_TEST_DIALOG };
public:
	BOOL Set_com(WPARAM wParam, LPARAM lParam);
	void C_Plus();
	void C_Sube();
	void C_De();
	void C_Multi();
	void C_Result();
	void C_Operate(double m_value_two);

	void C_Clear();
	void C_Comma();
	void C_BackSpace();
	void C_Sqrt(); //������
	void C_Squared(); //����
	void C_Boonsoo();
	void C_Allclear();
	void C_Buho();
	void C_Percent();

};
