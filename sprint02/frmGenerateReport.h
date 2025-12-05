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
	/// Summary for frmGenerateReport
	/// </summary>
	public ref class frmGenerateReport : public System::Windows::Forms::Form
	{
	public:
		frmGenerateReport(void)
		{
			InitializeComponent();
			LoadStudents();
			LoadCourses();
			LoadSemesters();
			SetupRadioButtons();
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

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmGenerateReport()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ rbCourseReport;
	private: System::Windows::Forms::RadioButton^ rbGradeReport;


	private: System::Windows::Forms::RadioButton^ rbStudentReport;
	private: System::Windows::Forms::ComboBox^ cmbSelectCourse;
	private: System::Windows::Forms::ComboBox^ cmbSemester;



	private: System::Windows::Forms::ComboBox^ cmbSelectStudent;
	private: System::Windows::Forms::TextBox^ txtAcademicYear;
	private: System::Windows::Forms::Button^ btnGenerate;
	private: System::Windows::Forms::Button^ btnExport;


	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnPrint;










	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->rbCourseReport = (gcnew System::Windows::Forms::RadioButton());
			this->rbGradeReport = (gcnew System::Windows::Forms::RadioButton());
			this->rbStudentReport = (gcnew System::Windows::Forms::RadioButton());
			this->cmbSelectCourse = (gcnew System::Windows::Forms::ComboBox());
			this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
			this->cmbSelectStudent = (gcnew System::Windows::Forms::ComboBox());
			this->txtAcademicYear = (gcnew System::Windows::Forms::TextBox());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->btnExport = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnPrint = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(324, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(207, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Generate Report";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rbCourseReport);
			this->groupBox1->Controls->Add(this->rbStudentReport);
			this->groupBox1->Controls->Add(this->rbGradeReport);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(31, 59);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(318, 176);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Select Report Type";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->cmbSelectStudent);
			this->groupBox2->Controls->Add(this->cmbSelectCourse);
			this->groupBox2->Controls->Add(this->cmbSemester);
			this->groupBox2->Controls->Add(this->txtAcademicYear);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(430, 59);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(494, 201);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Filters";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &frmGenerateReport::groupBox2_Enter);
			// 
			// rbCourseReport
			// 
			this->rbCourseReport->AutoSize = true;
			this->rbCourseReport->Location = System::Drawing::Point(18, 26);
			this->rbCourseReport->Name = L"rbCourseReport";
			this->rbCourseReport->Size = System::Drawing::Size(152, 24);
			this->rbCourseReport->TabIndex = 3;
			this->rbCourseReport->TabStop = true;
			this->rbCourseReport->Text = L"Course Report";
			this->rbCourseReport->UseVisualStyleBackColor = true;
			// 
			// rbGradeReport
			// 
			this->rbGradeReport->AutoSize = true;
			this->rbGradeReport->Location = System::Drawing::Point(18, 74);
			this->rbGradeReport->Name = L"rbGradeReport";
			this->rbGradeReport->Size = System::Drawing::Size(247, 24);
			this->rbGradeReport->TabIndex = 4;
			this->rbGradeReport->TabStop = true;
			this->rbGradeReport->Text = L"Grade Distribution Report";
			this->rbGradeReport->UseVisualStyleBackColor = true;
			// 
			// rbStudentReport
			// 
			this->rbStudentReport->AutoSize = true;
			this->rbStudentReport->Location = System::Drawing::Point(18, 47);
			this->rbStudentReport->Name = L"rbStudentReport";
			this->rbStudentReport->Size = System::Drawing::Size(269, 24);
			this->rbStudentReport->TabIndex = 5;
			this->rbStudentReport->TabStop = true;
			this->rbStudentReport->Text = L"Student Performance Report";
			this->rbStudentReport->UseVisualStyleBackColor = true;
			// 
			// cmbSelectCourse
			// 
			this->cmbSelectCourse->FormattingEnabled = true;
			this->cmbSelectCourse->Location = System::Drawing::Point(181, 73);
			this->cmbSelectCourse->Name = L"cmbSelectCourse";
			this->cmbSelectCourse->Size = System::Drawing::Size(224, 28);
			this->cmbSelectCourse->TabIndex = 6;
			this->cmbSelectCourse->SelectedIndexChanged += gcnew System::EventHandler(this, &frmGenerateReport::comboBox1_SelectedIndexChanged);
			// 
			// cmbSemester
			// 
			this->cmbSemester->FormattingEnabled = true;
			this->cmbSemester->Location = System::Drawing::Point(181, 124);
			this->cmbSemester->Name = L"cmbSemester";
			this->cmbSemester->Size = System::Drawing::Size(195, 28);
			this->cmbSemester->TabIndex = 7;
			// 
			// cmbSelectStudent
			// 
			this->cmbSelectStudent->FormattingEnabled = true;
			this->cmbSelectStudent->Location = System::Drawing::Point(181, 33);
			this->cmbSelectStudent->Name = L"cmbSelectStudent";
			this->cmbSelectStudent->Size = System::Drawing::Size(224, 28);
			this->cmbSelectStudent->TabIndex = 8;
			// 
			// txtAcademicYear
			// 
			this->txtAcademicYear->Location = System::Drawing::Point(181, 171);
			this->txtAcademicYear->Name = L"txtAcademicYear";
			this->txtAcademicYear->Size = System::Drawing::Size(195, 27);
			this->txtAcademicYear->TabIndex = 9;
			// 
		
			// btnGenerate
			// 
			this->btnGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGenerate->Location = System::Drawing::Point(49, 274);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(197, 31);
			this->btnGenerate->TabIndex = 10;
			this->btnGenerate->Text = L"Generate Report";
			this->btnGenerate->UseVisualStyleBackColor = true;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &frmGenerateReport::btnGenerate_Click);
			
			// 
			// btnExport
			// 
			this->btnExport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExport->Location = System::Drawing::Point(465, 274);
			this->btnExport->Name = L"btnExport";
			this->btnExport->Size = System::Drawing::Size(148, 31);
			this->btnExport->TabIndex = 11;
			this->btnExport->Text = L"Export to Excel";
			this->btnExport->UseVisualStyleBackColor = true;
			this->btnExport->Click += gcnew System::EventHandler(this, &frmGenerateReport::btnExport_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(619, 274);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(105, 31);
			this->btnCancel->TabIndex = 12;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmGenerateReport::btnCancel_Click);
			// 
			// btnPrint
			// 
			this->btnPrint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPrint->Location = System::Drawing::Point(252, 274);
			this->btnPrint->Name = L"btnPrint";
			this->btnPrint->Size = System::Drawing::Size(207, 31);
			this->btnPrint->TabIndex = 13;
			this->btnPrint->Text = L"Print Report";
			this->btnPrint->UseVisualStyleBackColor = true;
			this->btnPrint->Click += gcnew System::EventHandler(this, &frmGenerateReport::btnPrint_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(58, 318);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(666, 150);
			this->dataGridView1->TabIndex = 14;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(58, 474);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(666, 114);
			this->richTextBox1->TabIndex = 15;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Select Student:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Select Course:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 127);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Semester:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 171);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(141, 20);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Academic Year:";
			// 
			// frmGenerateReport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Cyan;
			this->ClientSize = System::Drawing::Size(956, 600);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnPrint);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnExport);
			this->Controls->Add(this->btnGenerate);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Name = L"frmGenerateReport";
			this->Text = L"Generate Report";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private:
	void SetupRadioButtons() {
		rbCourseReport->CheckedChanged += gcnew System::EventHandler(this, &frmGenerateReport::RadioButton_CheckedChanged);
		rbStudentReport->CheckedChanged += gcnew System::EventHandler(this, &frmGenerateReport::RadioButton_CheckedChanged);
		rbGradeReport->CheckedChanged += gcnew System::EventHandler(this, &frmGenerateReport::RadioButton_CheckedChanged);
	}

	void LoadStudents() {
		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
				"SELECT s.ID, CONCAT(s.StudentID, ' - ', u.FirstName, ' ', u.LastName) AS StudentName " +
				"FROM students s INNER JOIN users u ON s.UserID = u.ID " +
				"ORDER BY s.StudentID", sqlConn);
			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);
			cmbSelectStudent->DataSource = dt;
			cmbSelectStudent->DisplayMember = "StudentName";
			cmbSelectStudent->ValueMember = "ID";
			cmbSelectStudent->SelectedIndex = -1;
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading students: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void LoadCourses() {
		try {
			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
				"SELECT ID, CONCAT(CourseCode, ' - ', CourseTitle) AS CourseName " +
				"FROM courses ORDER BY CourseCode", sqlConn);
			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);
			cmbSelectCourse->DataSource = dt;
			cmbSelectCourse->DisplayMember = "CourseName";
			cmbSelectCourse->ValueMember = "ID";
			cmbSelectCourse->SelectedIndex = -1;
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading courses: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void LoadSemesters() {
		cmbSemester->Items->Clear();
		cmbSemester->Items->Add("All");
		cmbSemester->Items->Add("First Semester");
		cmbSemester->Items->Add("Second Semester");
		cmbSemester->Items->Add("Summer Session");
		cmbSemester->SelectedIndex = 0;
	}

	System::Void RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		// Enable/disable filters based on report type
		if (rbCourseReport->Checked) {
			cmbSelectStudent->Enabled = false;
			cmbSelectCourse->Enabled = true;
			cmbSemester->Enabled = true;
			txtAcademicYear->Enabled = true;
		}
		else if (rbStudentReport->Checked) {
			cmbSelectStudent->Enabled = true;
			cmbSelectCourse->Enabled = false;
			cmbSemester->Enabled = true;
			txtAcademicYear->Enabled = true;
		}
		else if (rbGradeReport->Checked) {
			cmbSelectStudent->Enabled = false;
			cmbSelectCourse->Enabled = true;
			cmbSemester->Enabled = true;
			txtAcademicYear->Enabled = true;
		}
	}

	System::Void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (rbCourseReport->Checked) {
			GenerateCourseReport();
		}
		else if (rbStudentReport->Checked) {
			GenerateStudentReport();
		}
		else if (rbGradeReport->Checked) {
			GenerateGradeDistributionReport();
		}
		else {
			MessageBox::Show("Please select a report type", "Selection Required",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	void GenerateCourseReport() {
		if (cmbSelectCourse->SelectedIndex == -1) {
			MessageBox::Show("Please select a course", "Selection Required",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			int courseID = Convert::ToInt32(cmbSelectCourse->SelectedValue);
			String^ semester = cmbSemester->Text;
			String^ year = txtAcademicYear->Text->Trim();

			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			String^ query = "SELECT s.StudentID, u.FirstName, u.LastName, g.Grade, g.GradePoints, " +
				"g.Semester, g.AcademicYear " +
				"FROM grades g " +
				"INNER JOIN students s ON g.StudentID = s.ID " +
				"INNER JOIN users u ON s.UserID = u.ID " +
				"WHERE g.CourseID = @cID";

			if (semester != "All") query += " AND g.Semester = @sem";
			if (year != "") query += " AND g.AcademicYear = @year";
			query += " ORDER BY s.StudentID";

			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(query, sqlConn);
			da->SelectCommand->Parameters->AddWithValue("@cID", courseID);
			if (semester != "All") da->SelectCommand->Parameters->AddWithValue("@sem", semester);
			if (year != "") da->SelectCommand->Parameters->AddWithValue("@year", year);

			sqlDT->Clear();
			da->Fill(sqlDT);
			dataGridView1->DataSource = sqlDT;

			// Generate summary
			richTextBox1->Text = "Course Report Summary:\n";
			richTextBox1->Text += "Total Students: " + sqlDT->Rows->Count + "\n";

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error generating report: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void GenerateStudentReport() {
		if (cmbSelectStudent->SelectedIndex == -1) {
			MessageBox::Show("Please select a student", "Selection Required",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			int studentID = Convert::ToInt32(cmbSelectStudent->SelectedValue);
			String^ semester = cmbSemester->Text;
			String^ year = txtAcademicYear->Text->Trim();

			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			String^ query = "SELECT c.CourseCode, c.CourseTitle, c.CourseCredit, " +
				"g.Grade, g.GradePoints, g.Semester, g.AcademicYear " +
				"FROM grades g " +
				"INNER JOIN courses c ON g.CourseID = c.ID " +
				"WHERE g.StudentID = @stID";

			if (semester != "All") query += " AND g.Semester = @sem";
			if (year != "") query += " AND g.AcademicYear = @year";
			query += " ORDER BY g.AcademicYear DESC, g.Semester";

			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(query, sqlConn);
			da->SelectCommand->Parameters->AddWithValue("@stID", studentID);
			if (semester != "All") da->SelectCommand->Parameters->AddWithValue("@sem", semester);
			if (year != "") da->SelectCommand->Parameters->AddWithValue("@year", year);

			sqlDT->Clear();
			da->Fill(sqlDT);
			dataGridView1->DataSource = sqlDT;

			// Calculate GPA
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT SUM(g.GradePoints * c.CourseCredit) / SUM(c.CourseCredit) as GPA " +
				"FROM grades g INNER JOIN courses c ON g.CourseID = c.ID WHERE g.StudentID = @stID";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@stID", studentID);
			Object^ gpaObj = sqlCmd->ExecuteScalar();
			double gpa = (gpaObj != nullptr && gpaObj != DBNull::Value) ? Convert::ToDouble(gpaObj) : 0.0;

			richTextBox1->Text = "Student Performance Summary:\n";
			richTextBox1->Text += "Total Courses: " + sqlDT->Rows->Count + "\n";
			richTextBox1->Text += "Cumulative GPA: " + gpa.ToString("0.00") + "\n";

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error generating report: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void GenerateGradeDistributionReport() {
		if (cmbSelectCourse->SelectedIndex == -1) {
			MessageBox::Show("Please select a course", "Selection Required",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			int courseID = Convert::ToInt32(cmbSelectCourse->SelectedValue);
			String^ semester = cmbSemester->Text;
			String^ year = txtAcademicYear->Text->Trim();

			if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			String^ query = "SELECT Grade, COUNT(*) as Count " +
				"FROM grades WHERE CourseID = @cID";

			if (semester != "All") query += " AND Semester = @sem";
			if (year != "") query += " AND AcademicYear = @year";
			query += " GROUP BY Grade ORDER BY FIELD(Grade, 'A', 'B+', 'B', 'C+', 'C', 'D+', 'D', 'E', 'F')";

			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(query, sqlConn);
			da->SelectCommand->Parameters->AddWithValue("@cID", courseID);
			if (semester != "All") da->SelectCommand->Parameters->AddWithValue("@sem", semester);
			if (year != "") da->SelectCommand->Parameters->AddWithValue("@year", year);

			sqlDT->Clear();
			da->Fill(sqlDT);
			dataGridView1->DataSource = sqlDT;

			// Generate summary
			richTextBox1->Text = "Grade Distribution Summary:\n";
			int total = 0;
			for each (DataRow ^ row in sqlDT->Rows) {
				total += Convert::ToInt32(row["Count"]);
			}
			richTextBox1->Text += "Total Grades: " + total + "\n\n";

			for each (DataRow ^ row in sqlDT->Rows) {
				String^ grade = row["Grade"]->ToString();
				int count = Convert::ToInt32(row["Count"]);
				double percentage = (total > 0) ? (count * 100.0 / total) : 0;
				richTextBox1->Text += grade + ": " + count + " (" + percentage.ToString("0.0") + "%)\n";
			}

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error generating report: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void btnExport_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Export to Excel functionality would be implemented here.\n" +
			"This would use a library like EPPlus or ClosedXML to export the data.", "Export",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void btnPrint_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Print functionality would be implemented here.\n" +
			"This would format and print the current report.", "Print",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
