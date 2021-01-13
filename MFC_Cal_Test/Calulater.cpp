//계산기의 기능을 구현하여 놓은 소스입니다. 2021-01-11 작업
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

IMPLEMENT_DYNAMIC(Calculater_LBH, CMFC_Cal_TestDlg) //CRuntimClass에 Calculater_LBH의 부모가 CMFC_Cal_TestDlg임을 알림.



Calculater_LBH::~Calculater_LBH()
{

}

void Calculater_LBH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Calculater_LBH, CMFC_Cal_TestDlg/*CDialog*/) //★메세지 맵입니다. 왼쪽엔 자신을 적고 오른쪽엔 '자신이 정의하지 않은 메세지가 있을 경우
	//따라갈 메세지'를 적습니다. 한마디로 그냥 부모를 적으면 됩니다.
	//이렇게 적을 경우, 선언되지 않은 메세지의 경우 부모(CMFC_Cal_TestDlg)를 따라가게 됩니다.
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



BOOL Calculater_LBH::Set_com(WPARAM wParam, LPARAM lParam)
{
		if (B_Number0 <= wParam&&wParam <= B_Number9) //리소스 헤더에 정의된 매크로 넘버를 0~9사이의 값인지 확인함 
	{
		CString str, number_str,str2;//문자열 선언
		number_str.Format(L"%d", wParam - B_Number0);//숫자'0'을 기준으로 한다. Ex. 8이면 1008-1000 = 8 인식
		
		if (m_step == 0)//연산자가 눌리지 않았을경우
		{
			GetDlgItemText(Print_Edit, str2);//에디트에 입력된 값을 str2변수에 저장
		}
		else if (m_step == 1) //연산자가 눌렸을경우
		{
			GetDlgItemText(Print_Edit, str); //에디트에 입력된 값을 str변수에 저장
			m_step = 0;
			m_value = _wtof(str);
		}
		SetDlgItemText(Print_Edit, str2 + number_str);//str에 저장된 값에 숫자값을 더해 출력
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

void  Calculater_LBH::C_Result() //결과
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

	//SetDlgItemInt(Print_Edit, m_value); //연산된 값을 화면에 출력
}

void  Calculater_LBH::C_Operate(double m_value_two) //사칙연산
{
	switch (m_operater_flag)
	{
	case 0://더하기
		m_value += m_value_two;
		break;
	case 1://빼기
		m_value -= m_value_two;
		break;
	case 2://곱하기
		m_value *= m_value_two;
		break;
	case 3://나누기
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

void  Calculater_LBH::C_Clear() //클리어 버튼
{
	SetDlgItemText(Print_Edit, L" ");

	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);

}

void  Calculater_LBH::C_Comma() //콤마
{
	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);

}

void  Calculater_LBH::C_BackSpace() //백스페이스
{
	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);

}

void  Calculater_LBH::C_Sqrt() //제곱근
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

void  Calculater_LBH::C_Squared() //제곱
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

void  Calculater_LBH::C_Boonsoo() //분수
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


void  Calculater_LBH::C_Allclear() //올클리어
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

void  Calculater_LBH::C_Buho() //부호
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

void  Calculater_LBH::C_Percent() //비율
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