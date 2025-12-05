#pragma once

namespace AshesiMIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmViewGrades
	/// </summary>
	public ref class frmViewGrades : public System::Windows::Forms::Form
	{
	public:
		frmViewGrades(int studentID)
		{
			InitializeComponent();
			currentStudentID = studentID;
			LoadStudentInfo();
			LoadFilters();
			LoadAllGrades();
			//
			//TODO: Add the constructor code here
			//
		}
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "server=localhost;port=4306;uid=root;pwd=;database=ahsesimis;";
		int currentStudentID = 0;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmViewGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblStudentInfo;
	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ cmbSemester;
	private: System::Windows::Forms::ComboBox^ cmbAcademicYear;
	private: System::Windows::Forms::Button^ btnViewAll;
	private: System::Windows::Forms::Button^ btnFilter;
	private: System::Windows::Forms::DataGridView^ dgvGrades;
	private: System::Windows::Forms::Button^ btnClose;






	private: System::Windows::Forms::Button^ btnPrint;

	private: System::Windows::Forms::Label^ lblSGPA;


	private: System::Windows::Forms::Label^ lblCGPA;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ProgressBar^ pbGradeDistribution;
	private: System::Windows::Forms::Label^ lblTotalCourses;
	private: System::Windows::Forms::Label^ lblTotalCredits;





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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblStudentInfo = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
			this->cmbAcademicYear = (gcnew System::Windows::Forms::ComboBox());
			this->btnViewAll = (gcnew System::Windows::Forms::Button());
			this->btnFilter = (gcnew System::Windows::Forms::Button());
			this->dgvGrades = (gcnew System::Windows::Forms::DataGridView());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnPrint = (gcnew System::Windows::Forms::Button());
			this->lblSGPA = (gcnew System::Windows::Forms::Label());
			this->lblCGPA = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblTotalCourses = (gcnew System::Windows::Forms::Label());
			this->lblTotalCredits = (gcnew System::Windows::Forms::Label());
			this->pbGradeDistribution = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvGrades))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(330, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"My Grades";
			// 
			// lblStudentInfo
			// 
			this->lblStudentInfo->AutoSize = true;
			this->lblStudentInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentInfo->Location = System::Drawing::Point(32, 42);
			this->lblStudentInfo->Name = L"lblStudentInfo";
			this->lblStudentInfo->Size = System::Drawing::Size(136, 25);
			this->lblStudentInfo->TabIndex = 1;
			this->lblStudentInfo->Text = L"Student Info:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(31, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(196, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Filter By Semester:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(31, 118);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(250, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Filter By Academic Year:";
			this->label4->Click += gcnew System::EventHandler(this, &frmViewGrades::label4_Click);
			// 
			// cmbSemester
			// 
			this->cmbSemester->FormattingEnabled = true;
			this->cmbSemester->Location = System::Drawing::Point(228, 81);
			this->cmbSemester->Name = L"cmbSemester";
			this->cmbSemester->Size = System::Drawing::Size(314, 24);
			this->cmbSemester->TabIndex = 4;
			// 
			// cmbAcademicYear
			// 
			this->cmbAcademicYear->FormattingEnabled = true;
			this->cmbAcademicYear->Location = System::Drawing::Point(277, 118);
			this->cmbAcademicYear->Name = L"cmbAcademicYear";
			this->cmbAcademicYear->Size = System::Drawing::Size(175, 24);
			this->cmbAcademicYear->TabIndex = 5;
			// 
			// btnViewAll
			// 
			this->btnViewAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnViewAll->Location = System::Drawing::Point(36, 162);
			this->btnViewAll->Name = L"btnViewAll";
			this->btnViewAll->Size = System::Drawing::Size(175, 41);
			this->btnViewAll->TabIndex = 6;
			this->btnViewAll->Text = L"View All Grades";
			this->btnViewAll->UseVisualStyleBackColor = true;
			this->btnViewAll->Click += gcnew System::EventHandler(this, &frmViewGrades::btnViewAll_Click);
			
			// 
			// btnFilter
			// 
			this->btnFilter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFilter->Location = System::Drawing::Point(248, 162);
			this->btnFilter->Name = L"btnFilter";
			this->btnFilter->Size = System::Drawing::Size(91, 34);
			this->btnFilter->TabIndex = 7;
			this->btnFilter->Text = L"Filter";
			this->btnFilter->UseVisualStyleBackColor = true;
			this->btnFilter->Click += gcnew System::EventHandler(this, &frmViewGrades::btnFilter_Click);
			
			// 
			// dgvGrades
			// 
			this->dgvGrades->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvGrades->Location = System::Drawing::Point(36, 209);
			this->dgvGrades->Name = L"dgvGrades";
			this->dgvGrades->RowHeadersWidth = 51;
			this->dgvGrades->RowTemplate->Height = 24;
			this->dgvGrades->Size = System::Drawing::Size(762, 182);
			this->dgvGrades->TabIndex = 8;
			// 
			// btnClose
			// 
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClose->Location = System::Drawing::Point(987, 531);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(110, 33);
			this->btnClose->TabIndex = 9;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmViewGrades::btnClose_Click);
			// 
			// btnPrint
			// 
			this->btnPrint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPrint->Location = System::Drawing::Point(758, 531);
			this->btnPrint->Name = L"btnPrint";
			this->btnPrint->Size = System::Drawing::Size(181, 33);
			this->btnPrint->TabIndex = 10;
			this->btnPrint->Text = L"Print Transcript";
			this->btnPrint->UseVisualStyleBackColor = true;
			this->btnPrint->Click += gcnew System::EventHandler(this, &frmViewGrades::btnPrint_Click);
			
			// 
			// lblSGPA
			// 
			this->lblSGPA->AutoSize = true;
			this->lblSGPA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSGPA->Location = System::Drawing::Point(382, 419);
			this->lblSGPA->Name = L"lblSGPA";
			this->lblSGPA->Size = System::Drawing::Size(147, 22);
			this->lblSGPA->TabIndex = 11;
			this->lblSGPA->Text = L"Semester GPA:";
			// 
			// lblCGPA
			// 
			this->lblCGPA->AutoSize = true;
			this->lblCGPA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCGPA->Location = System::Drawing::Point(32, 419);
			this->lblCGPA->Name = L"lblCGPA";
			this->lblCGPA->Size = System::Drawing::Size(162, 22);
			this->lblCGPA->TabIndex = 12;
			this->lblCGPA->Text = L"Cumulative GPA:";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Cyan;
			this->groupBox1->Controls->Add(this->lblTotalCredits);
			this->groupBox1->Controls->Add(this->pbGradeDistribution);
			this->groupBox1->Controls->Add(this->lblTotalCourses);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(36, 453);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(640, 120);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Grade Summary";
			// 
			// lblTotalCourses
			// 
			this->lblTotalCourses->AutoSize = true;
			this->lblTotalCourses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalCourses->Location = System::Drawing::Point(237, 23);
			this->lblTotalCourses->Name = L"lblTotalCourses";
			this->lblTotalCourses->Size = System::Drawing::Size(136, 22);
			this->lblTotalCourses->TabIndex = 14;
			this->lblTotalCourses->Text = L"Total Courses";
			// 
			// lblTotalCredits
			// 
			this->lblTotalCredits->AutoSize = true;
			this->lblTotalCredits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalCredits->Location = System::Drawing::Point(237, 68);
			this->lblTotalCredits->Name = L"lblTotalCredits";
			this->lblTotalCredits->Size = System::Drawing::Size(126, 22);
			this->lblTotalCredits->TabIndex = 15;
			this->lblTotalCredits->Text = L"Total Credits";
			// 
			// pbGradeDistribution
			// 
			this->pbGradeDistribution->BackColor = System::Drawing::Color::Chartreuse;
			this->pbGradeDistribution->ForeColor = System::Drawing::SystemColors::Desktop;
			this->pbGradeDistribution->Location = System::Drawing::Point(54, 33);
			this->pbGradeDistribution->Name = L"pbGradeDistribution";
			this->pbGradeDistribution->Size = System::Drawing::Size(100, 23);
			this->pbGradeDistribution->TabIndex = 0;
			// 
			// frmViewGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gold;
			this->ClientSize = System::Drawing::Size(1158, 624);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lblCGPA);
			this->Controls->Add(this->lblSGPA);
			this->Controls->Add(this->btnPrint);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->dgvGrades);
			this->Controls->Add(this->btnFilter);
			this->Controls->Add(this->btnViewAll);
			this->Controls->Add(this->cmbAcademicYear);
			this->Controls->Add(this->cmbSemester);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblStudentInfo);
			this->Controls->Add(this->label1);
			this->Name = L"frmViewGrades";
			this->Text = L"View Your Grades";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvGrades))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private:
	void LoadStudentInfo() {
		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT s.StudentID, u.FirstName, u.LastName, p.Programme, s.Level " +
				"FROM students s " +
				"INNER JOIN users u ON s.UserID = u.ID " +
				"INNER JOIN programmes p ON s.ProgrammeID = p.ID " +
				"WHERE s.ID = @id";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				lblStudentInfo->Text = "Student: " + sqlDR["StudentID"]->ToString() + " - " +
					sqlDR["FirstName"]->ToString() + " " + sqlDR["LastName"]->ToString() +
					" | Programme: " + sqlDR["Programme"]->ToString() +
					" | Level: " + sqlDR["Level"]->ToString();
			}
			sqlDR->Close();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading student info: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void LoadFilters() {
		// Load semesters
		cmbSemester->Items->Clear();
		cmbSemester->Items->Add("All");
		cmbSemester->Items->Add("First Semester");
		cmbSemester->Items->Add("Second Semester");
		cmbSemester->Items->Add("Summer Session");
		cmbSemester->SelectedIndex = 0;

		// Load academic years from grades
		try {
			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
				"SELECT DISTINCT AcademicYear FROM grades WHERE StudentID = @id ORDER BY AcademicYear DESC", sqlConn);
			da->SelectCommand->Parameters->AddWithValue("@id", currentStudentID);
			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);

			cmbAcademicYear->Items->Clear();
			cmbAcademicYear->Items->Add("All");
			for each (DataRow ^ row in dt->Rows) {
				cmbAcademicYear->Items->Add(row["AcademicYear"]->ToString());
			}
			cmbAcademicYear->SelectedIndex = 0;
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading filters: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void LoadAllGrades() {
		LoadGrades("", "");
	}

	void LoadGrades(String^ semester, String^ academicYear) {
		try {
			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			String^ query = "SELECT g.ID, c.CourseCode, c.CourseTitle, c.CourseCredit as Credits, " +
				"g.Grade, g.GradePoints, g.Semester, g.AcademicYear " +
				"FROM grades g " +
				"INNER JOIN courses c ON g.CourseID = c.ID " +
				"WHERE g.StudentID = @id";

			if (semester != "" && semester != "All") {
				query += " AND g.Semester = @sem";
			}
			if (academicYear != "" && academicYear != "All") {
				query += " AND g.AcademicYear = @year";
			}
			query += " ORDER BY g.AcademicYear DESC, g.Semester";

			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(query, sqlConn);
			da->SelectCommand->Parameters->AddWithValue("@id", currentStudentID);
			if (semester != "" && semester != "All") {
				da->SelectCommand->Parameters->AddWithValue("@sem", semester);
			}
			if (academicYear != "" && academicYear != "All") {
				da->SelectCommand->Parameters->AddWithValue("@year", academicYear);
			}

			sqlDT->Clear();
			da->Fill(sqlDT);
			dgvGrades->DataSource = sqlDT;
			dgvGrades->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			sqlConn->Close();

			CalculateGPA();
			UpdateSummary();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading grades: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void CalculateGPA() {
		try {
			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			// Calculate CGPA (all grades)
			sqlCmd->CommandText = "SELECT SUM(g.GradePoints * c.CourseCredit) / SUM(c.CourseCredit) as CGPA " +
				"FROM grades g INNER JOIN courses c ON g.CourseID = c.ID " +
				"WHERE g.StudentID = @id";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
			Object^ cgpaObj = sqlCmd->ExecuteScalar();
			double cgpa = (cgpaObj != nullptr && cgpaObj != DBNull::Value) ? Convert::ToDouble(cgpaObj) : 0.0;
			lblCGPA->Text = "Cumulative GPA: " + cgpa.ToString("0.00");

			// Calculate SGPA (current semester if filtered)
			String^ semester = cmbSemester->Text;
			String^ year = cmbAcademicYear->Text;

			if (semester != "All" && year != "All") {
				sqlCmd->CommandText = "SELECT SUM(g.GradePoints * c.CourseCredit) / SUM(c.CourseCredit) as SGPA " +
					"FROM grades g INNER JOIN courses c ON g.CourseID = c.ID " +
					"WHERE g.StudentID = @id AND g.Semester = @sem AND g.AcademicYear = @year";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
				sqlCmd->Parameters->AddWithValue("@sem", semester);
				sqlCmd->Parameters->AddWithValue("@year", year);
				Object^ sgpaObj = sqlCmd->ExecuteScalar();
				double sgpa = (sgpaObj != nullptr && sgpaObj != DBNull::Value) ? Convert::ToDouble(sgpaObj) : 0.0;
				lblSGPA->Text = "Semester GPA: " + sgpa.ToString("0.00");
			}
			else {
				lblSGPA->Text = "Semester GPA: N/A (Select specific semester)";
			}

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error calculating GPA: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void UpdateSummary() {
		try {
			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			// Total courses
			sqlCmd->CommandText = "SELECT COUNT(*) FROM grades WHERE StudentID = @id";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
			int totalCourses = Convert::ToInt32(sqlCmd->ExecuteScalar());
			lblTotalCourses->Text = "Total Courses: " + totalCourses.ToString();

			// Total credits
			sqlCmd->CommandText = "SELECT SUM(c.CourseCredit) FROM grades g " +
				"INNER JOIN courses c ON g.CourseID = c.ID WHERE g.StudentID = @id";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
			Object^ creditsObj = sqlCmd->ExecuteScalar();
			int totalCredits = (creditsObj != nullptr && creditsObj != DBNull::Value) ? Convert::ToInt32(creditsObj) : 0;
			lblTotalCredits->Text = "Total Credits: " + totalCredits.ToString();

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error updating summary: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void btnViewAll_Click(System::Object^ sender, System::EventArgs^ e) {
		cmbSemester->SelectedIndex = 0;
		cmbAcademicYear->SelectedIndex = 0;
		LoadAllGrades();
	}

	System::Void btnFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ semester = cmbSemester->Text;
		String^ year = cmbAcademicYear->Text;
		LoadGrades(semester, year);
	}

	System::Void btnPrint_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Print functionality would be implemented here.\n" +
			"This would generate a formatted transcript document.", "Print Transcript",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
