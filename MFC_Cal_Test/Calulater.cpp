//������ ����� �����Ͽ� ���� �ҽ��Դϴ�. 2021-01-11 �۾�
#include "stdafx.h"
#include "Calculater.h"
#include "MFC_Cal_Test.h"
#include "MFC_Cal_TestDlg.h"
#include "afxdialogex.h"
#include "Resource.h"

/*
#ifdef _DEBUGCChildDlg
#define new DEBUG_NEW
#endif
*/

IMPLEMENT_DYNAMIC(Calculater_LBH, CMFC_Cal_TestDlg) //CRuntimClass�� Calculater_LBH�� �θ� CMFC_Cal_TestDlg���� �˸�.



Calculater_LBH::~Calculater_LBH()
{

}

void Calculater_LBH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Calculater_LBH, CMFC_Cal_TestDlg/*CDialog*/) //�ڸ޼��� ���Դϴ�. ���ʿ� �ڽ��� ���� �����ʿ� '�ڽ��� �������� ���� �޼����� ���� ���
	//���� �޼���'�� �����ϴ�. �Ѹ���� �׳� �θ� ������ �˴ϴ�.
	//�̷��� ���� ���, ������� ���� �޼����� ��� �θ�(CMFC_Cal_TestDlg)�� ���󰡰� �˴ϴ�.
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



BOOL Calculater_LBH::Set_com(WPARAM wParam, LPARAM lParam)
{
		if (B_Number0 <= wParam&&wParam <= B_Number9) //���ҽ� ����� ���ǵ� ��ũ�� �ѹ��� 0~9������ ������ Ȯ���� 
	{
		CString str, number_str,str2;//���ڿ� ����
		number_str.Format(L"%d", wParam - B_Number0);//����'0'�� �������� �Ѵ�. Ex. 8�̸� 1008-1000 = 8 �ν�
		
		if (m_step == 0)//�����ڰ� ������ �ʾ������
		{
			GetDlgItemText(Print_Edit, str2);//����Ʈ�� �Էµ� ���� str2������ ����
		}
		else if (m_step == 1) //�����ڰ� ���������
		{
			GetDlgItemText(Print_Edit, str); //����Ʈ�� �Էµ� ���� str������ ����
			m_step = 0;
			m_value = _wtof(str);
		}
		SetDlgItemText(Print_Edit, str2 + number_str);//str�� ����� ���� ���ڰ��� ���� ���
	}
	m_flant = m_value;
	return Calculater_LBH::Set_com(wParam, lParam);
}

void Calculater_LBH::C_Plus()
{
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 0;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '+');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}

void Calculater_LBH::C_Sube()
{
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}
	m_operater_flag = 1;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '-');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);

}

void Calculater_LBH::C_De()
{
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 3;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '/');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);

}

void Calculater_LBH::C_Multi()
{
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 2;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '*');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);


}

void  Calculater_LBH::C_Result() //���
{
	CString str;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, str);
	m_value_two = _wtof(str);

	CEdit* pEdit2 = (CEdit*)GetDlgItem(Print_Edit2);
	pEdit2->SetWindowTextW(L" ");

	M_Operate(m_value_two);

	m_count = 0;

	str.Format(L"%f", m_value);
	str.TrimRight(L"0");
	str.TrimRight(L".");
	SetDlgItemText(Print_Edit, str);

	//SetDlgItemInt(Print_Edit, m_value); //����� ���� ȭ�鿡 ���
}

void  Calculater_LBH::C_Operate(double m_value_two) //��Ģ����
{
	switch (m_operater_flag)
	{
	case 0://���ϱ�
		m_value += m_value_two;
		break;
	case 1://����
		m_value -= m_value_two;
		break;
	case 2://���ϱ�
		m_value *= m_value_two;
		break;
	case 3://������
		if (m_value_two != 0)
		{
			m_value /= m_value_two;
		}
		else
		{
			m_value = 0;
		}
		break;
	}
}

void  Calculater_LBH::C_Clear() //Ŭ���� ��ư
{
	SetDlgItemText(Print_Edit, L" ");

	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);

}

void  Calculater_LBH::C_Comma() //�޸�
{
	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);

}

void  Calculater_LBH::C_BackSpace() //�齺���̽�
{
	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);

}

void  Calculater_LBH::C_Sqrt() //������
{
	UpdateData(TRUE);

	CString str, omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	omg.Format(L"%f", sqrt(m_value_two));
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);

}

void  Calculater_LBH::C_Squared() //����
{
	UpdateData(TRUE);

	CString str, omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	omg.Format(L"%f", m_value_two*m_value_two);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}

void  Calculater_LBH::C_Boonsoo() //�м�
{
	UpdateData(TRUE);

	CString str, omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	omg.Format(L"%f", 1 / m_value_two);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}


void  Calculater_LBH::C_Allclear() //��Ŭ����
{
	UpdateData(TRUE);

	CEdit* pEdit = (CEdit*)GetDlgItem(Print_Edit);
	pEdit->SetWindowTextW(L" ");

	CEdit* pEdit2 = (CEdit*)GetDlgItem(Print_Edit2);
	pEdit2->SetWindowTextW(L" ");

	m_value = 0;
	m_step = 0;
	m_operater_flag = 0;
	m_count = 0;

	UpdateData(FALSE);
}

void  Calculater_LBH::C_Buho() //��ȣ
{
	UpdateData(TRUE);

	CString omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	omg.Format(L"%f", -1 * m_value_two);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}

void  Calculater_LBH::C_Percent() //����
{
	UpdateData(TRUE);

	CString omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	double m_flant2;
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_flant2 = m_flant * (m_value_two / 100.0);
	omg.Format(L"%f", m_flant2);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}