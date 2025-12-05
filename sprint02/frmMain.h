#pragma once
#include "user.h"
#include "frmDepartment.h"
#include "frmCourses.h"
#include "frmprogrammes.h"
#include "frmRegisterFaculty.h"
#include "frmRegisterStudent.h"
#include "frmAddFaculty.h"
#include "frmAddUsers.h"
#include "frmEnterGrade.h"
#include "frmRegisterCourse.h"
#include "frmViewGrades.h"
#include "frmGenerateReport.h"
namespace AshesiMIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	private:
		User^ currentUser;

	public:
		frmMain(User^ user)
		{
			InitializeComponent();
			currentUser = user;
			ConfigureMenuBasedOnRole();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem1;

	private: System::Windows::Forms::ToolStripMenuItem^ administrationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ systemSetupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterGradeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generateReportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addDepartmentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addUsersToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addProgrammesToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterGradeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateReportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->systemSetupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addDepartmentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addUsersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addProgrammesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->facultyToolStripMenuItem,
					this->facultyToolStripMenuItem1, this->administrationToolStripMenuItem, this->systemSetupToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(836, 33);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->BackColor = System::Drawing::SystemColors::HotTrack;
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->registerCourseToolStripMenuItem,
					this->viewGradesToolStripMenuItem
			});
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(87, 29);
			this->facultyToolStripMenuItem->Text = L"Student";
			// 
			// registerCourseToolStripMenuItem
			// 
			this->registerCourseToolStripMenuItem->Name = L"registerCourseToolStripMenuItem";
			this->registerCourseToolStripMenuItem->Size = System::Drawing::Size(221, 30);
			this->registerCourseToolStripMenuItem->Text = L"Register Course";
			// 
			// viewGradesToolStripMenuItem
			// 
			this->viewGradesToolStripMenuItem->Name = L"viewGradesToolStripMenuItem";
			this->viewGradesToolStripMenuItem->Size = System::Drawing::Size(221, 30);
			this->viewGradesToolStripMenuItem->Text = L"View Grades";
			// 
			// facultyToolStripMenuItem1
			// 
			this->facultyToolStripMenuItem1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->facultyToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->enterGradeToolStripMenuItem,
					this->generateReportToolStripMenuItem
			});
			this->facultyToolStripMenuItem1->Name = L"facultyToolStripMenuItem1";
			this->facultyToolStripMenuItem1->Size = System::Drawing::Size(80, 29);
			this->facultyToolStripMenuItem1->Text = L"Faculty";
			// 
			// enterGradeToolStripMenuItem
			// 
			this->enterGradeToolStripMenuItem->Name = L"enterGradeToolStripMenuItem";
			this->enterGradeToolStripMenuItem->Size = System::Drawing::Size(226, 30);
			this->enterGradeToolStripMenuItem->Text = L"Enter Grade";
			// 
			// generateReportToolStripMenuItem
			// 
			this->generateReportToolStripMenuItem->Name = L"generateReportToolStripMenuItem";
			this->generateReportToolStripMenuItem->Size = System::Drawing::Size(226, 30);
			this->generateReportToolStripMenuItem->Text = L"Generate Report";
			// 
			// administrationToolStripMenuItem
			// 
			this->administrationToolStripMenuItem->BackColor = System::Drawing::SystemColors::Info;
			this->administrationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->registerFacultyToolStripMenuItem,
					this->registerStudentToolStripMenuItem
			});
			this->administrationToolStripMenuItem->Name = L"administrationToolStripMenuItem";
			this->administrationToolStripMenuItem->Size = System::Drawing::Size(143, 29);
			this->administrationToolStripMenuItem->Text = L"Administration";
			// 
			// registerFacultyToolStripMenuItem
			// 
			this->registerFacultyToolStripMenuItem->Name = L"registerFacultyToolStripMenuItem";
			this->registerFacultyToolStripMenuItem->Size = System::Drawing::Size(227, 30);
			this->registerFacultyToolStripMenuItem->Text = L"Register Faculty";
			this->registerFacultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerFacultyToolStripMenuItem_Click);
			// 
			// registerStudentToolStripMenuItem
			// 
			this->registerStudentToolStripMenuItem->Name = L"registerStudentToolStripMenuItem";
			this->registerStudentToolStripMenuItem->Size = System::Drawing::Size(227, 30);
			this->registerStudentToolStripMenuItem->Text = L"Register Student";
			this->registerStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerStudentToolStripMenuItem_Click);
			// 
			// systemSetupToolStripMenuItem
			// 
			this->systemSetupToolStripMenuItem->BackColor = System::Drawing::SystemColors::GrayText;
			this->systemSetupToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->addFacultyToolStripMenuItem,
					this->addDepartmentToolStripMenuItem, this->addCourseToolStripMenuItem, this->addUsersToolStripMenuItem, this->addProgrammesToolStripMenuItem
			});
			this->systemSetupToolStripMenuItem->Name = L"systemSetupToolStripMenuItem";
			this->systemSetupToolStripMenuItem->Size = System::Drawing::Size(134, 29);
			this->systemSetupToolStripMenuItem->Text = L"System Setup";
			// 
			// addFacultyToolStripMenuItem
			// 
			this->addFacultyToolStripMenuItem->Name = L"addFacultyToolStripMenuItem";
			this->addFacultyToolStripMenuItem->Size = System::Drawing::Size(239, 30);
			this->addFacultyToolStripMenuItem->Text = L"Add Faculty";
			this->addFacultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addFacultyToolStripMenuItem_Click);
			// 
			// addDepartmentToolStripMenuItem
			// 
			this->addDepartmentToolStripMenuItem->Name = L"addDepartmentToolStripMenuItem";
			this->addDepartmentToolStripMenuItem->Size = System::Drawing::Size(239, 30);
			this->addDepartmentToolStripMenuItem->Text = L"Add Department";
			this->addDepartmentToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addDepartmentToolStripMenuItem_Click);
			// 
			// addCourseToolStripMenuItem
			// 
			this->addCourseToolStripMenuItem->Name = L"addCourseToolStripMenuItem";
			this->addCourseToolStripMenuItem->Size = System::Drawing::Size(239, 30);
			this->addCourseToolStripMenuItem->Text = L"Add Course";
			this->addCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addCourseToolStripMenuItem_Click_1);
			// 
			// addUsersToolStripMenuItem
			// 
			this->addUsersToolStripMenuItem->Name = L"addUsersToolStripMenuItem";
			this->addUsersToolStripMenuItem->Size = System::Drawing::Size(239, 30);
			this->addUsersToolStripMenuItem->Text = L"Add Users";
			this->addUsersToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addUsersToolStripMenuItem_Click);
		

			// 
			// addProgrammesToolStripMenuItem
			// 
			this->addProgrammesToolStripMenuItem->Name = L"addProgrammesToolStripMenuItem";
			this->addProgrammesToolStripMenuItem->Size = System::Drawing::Size(239, 30);
			this->addProgrammesToolStripMenuItem->Text = L"Add Programmes";
			this->addProgrammesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addProgrammesToolStripMenuItem_Click);
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 33);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(836, 33);
			this->menuStrip2->TabIndex = 2;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fileToolStripMenuItem.Image")));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(95, 29);
			this->fileToolStripMenuItem->Text = L"image";
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowText;
			this->ClientSize = System::Drawing::Size(836, 408);
			this->Controls->Add(this->menuStrip2);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmMain";
			this->Text = L"Ashesi MIS";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMain::frmMain_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void frmMain_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// Optional confirmation
		if (MessageBox::Show(
			"Do you want to exit?", "Confirm Exit", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			// Close the entire app
			Application::Exit();
			//return;
		}
		else {
			e->Cancel = true;  // cancel closing
			return;
		}
	}


private: System::Void addDepartmentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	AshesiMIS::frmDepartment frmDept;
	frmDept.ShowDialog();
}

private: System::Void addCourseToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
	AshesiMIS::frmCourses^ frmCourses = gcnew AshesiMIS::frmCourses();
	frmCourses->ShowDialog();
}
private: System::Void addProgrammesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	AshesiMIS::frmprogrammes^ frmProgrammes = gcnew AshesiMIS::frmprogrammes();
	frmProgrammes->ShowDialog();
}


private: System::Void addFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	AshesiMIS::frmAddFaculty^ frmAddFaculty = gcnew AshesiMIS::frmAddFaculty();
	frmAddFaculty->ShowDialog();
}

private: System::Void registerFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	AshesiMIS::frmRegisterFaculty^ frmRegFaculty = gcnew AshesiMIS::frmRegisterFaculty();
	frmRegFaculty->ShowDialog();
}

private: System::Void registerStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	AshesiMIS::frmRegisterStudent^ frmRegStudent = gcnew AshesiMIS::frmRegisterStudent();
	frmRegStudent->ShowDialog();
}

private: System::Void addUsersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	AshesiMIS::frmAddUsers^ frmAddU = gcnew AshesiMIS::frmAddUsers();
	frmAddU->ShowDialog();
}

private:
	void ConfigureMenuBasedOnRole() {
		
		facultyToolStripMenuItem->Visible = false;
		facultyToolStripMenuItem1->Visible = false;
		administrationToolStripMenuItem->Visible = false;
		systemSetupToolStripMenuItem->Visible = false;

		if (currentUser->roleNum == 3) { // Student
			facultyToolStripMenuItem->Visible = true;

			registerCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerCourseToolStripMenuItem_Click);
			viewGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::viewGradesToolStripMenuItem_Click);
		}
		else if (currentUser->roleNum == 2) { // Faculty
			facultyToolStripMenuItem1->Visible = true;

			
			enterGradeToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::enterGradeToolStripMenuItem_Click);
			generateReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::generateReportToolStripMenuItem_Click);
		}
		else if (currentUser->roleNum == 1) { // Administrator
			administrationToolStripMenuItem->Visible = true;
			systemSetupToolStripMenuItem->Visible = true;

			
		}
	}



private:
	
	System::Void registerCourseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentUser->studentID == 0) {
			MessageBox::Show("Student ID not found. Please contact administrator.", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		AshesiMIS::frmRegisterCourse^ frmRegCourse = gcnew AshesiMIS::frmRegisterCourse(currentUser->studentID);
		frmRegCourse->ShowDialog();
	}

	System::Void viewGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentUser->studentID == 0) {
			MessageBox::Show("Student ID not found. Please contact administrator.", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		AshesiMIS::frmViewGrades^ frmViewGrades = gcnew AshesiMIS::frmViewGrades(currentUser->studentID);
		frmViewGrades->ShowDialog();
	}

	
	System::Void enterGradeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AshesiMIS::frmEnterGrade^ frmEnterGrade = gcnew AshesiMIS::frmEnterGrade();
		frmEnterGrade->ShowDialog();
	}

	System::Void generateReportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AshesiMIS::frmGenerateReport^ frmGenerateReport = gcnew AshesiMIS::frmGenerateReport();
		frmGenerateReport->ShowDialog();
	}
};
}
