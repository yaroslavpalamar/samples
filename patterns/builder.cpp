#include <iostream>
#include <string>

using namespace std;

// Builder
class CReportBuilder 
{
public:
	virtual ~CReportBuilder() {};

	virtual void CreateHeader()  = 0;
	virtual void CreateBody() = 0;
	virtual void CreateFooter() = 0;

	virtual void Print()
	{
		cout << m_strReport << endl;
	};

protected:
	string m_strReport;
};
// Конкретний будівельник 1
struct CTextReportBuilder : public CReportBuilder 
{
	virtual ~CTextReportBuilder() {};

	virtual void CreateHeader()
	{
		m_strReport.append("SIMPLE REPORT'S HEADER \n");
	};
	virtual void CreateBody()
	{
		m_strReport.append("\n\"Simple Report's Main Text\"\n \n");
	};
	virtual void CreateFooter()
	{
		m_strReport.append("Simple Report's Footer \n");
	};
};
// Конкретний будівельник 2
struct CHTMLReportBuilder : public CReportBuilder 
{
	virtual ~CHTMLReportBuilder() {};

	virtual void CreateHeader()
	{
		m_strReport.append("<HTML><BODY> \n");
		m_strReport.append("<H1>HTML REPORT'S HEADER</H1> \n");
	};
	virtual void CreateBody()
	{
		m_strReport.append("<p>\"HTML Report's Main Text\"</p> \n");
	};
	virtual void CreateFooter()
	{
		m_strReport.append("<p><i>HTML Report's Footer</i></p> \n");
		m_strReport.append("</BODY></HTML>");
	};
};
// Director. Створює продукт використовуючи інтерфейс Будівельника
void CreateReport(CReportBuilder& report)
{
	report.CreateHeader();
	report.CreateBody();
	report.CreateFooter();
};

int main()
{
	CHTMLReportBuilder Report; // Product
	CreateReport(Report);
	Report.Print();
}

