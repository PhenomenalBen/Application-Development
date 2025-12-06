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
	/// Summary for frmEnterGrade
	/// </summary>
	public ref class frmEnterGrade : public System::Windows::Forms::Form
	{
	public:
		frmEnterGrade(void)
		{
			
			InitializeComponent();  
			LoadCourses();
			LoadStudents();
			LoadGrades();
			LoadSemesters();
			cmbGrade->Items->AddRange(gcnew array<String^>{"A+", "A", "B+", "B", "C+", "C", "D+", "D", "E", "I"});
			
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
		~frmEnterGrade()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cmbSelectStudent;
	private: System::Windows::Forms::ComboBox^ cmbSelectCourse;
	protected:


	private: System::Windows::Forms::ComboBox^ cmbGrade;

	private: System::Windows::Forms::ComboBox^ cmbSemester;
	private: System::Windows::Forms::TextBox^ txtGradePoints;


	private: System::Windows::Forms::TextBox^ txtAcademicYear;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnCancel;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

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
			this->cmbSelectStudent = (gcnew System::Windows::Forms::ComboBox());
			this->cmbSelectCourse = (gcnew System::Windows::Forms::ComboBox());
			this->cmbGrade = (gcnew System::Windows::Forms::ComboBox());
			this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
			this->txtGradePoints = (gcnew System::Windows::Forms::TextBox());
			this->txtAcademicYear = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(297, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(195, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Grade Entrance";
			// 
			// cmbSelectStudent
			// 
			this->cmbSelectStudent->FormattingEnabled = true;
			this->cmbSelectStudent->Location = System::Drawing::Point(197, 127);
			this->cmbSelectStudent->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->cmbSelectStudent->Name = L"cmbSelectStudent";
			this->cmbSelectStudent->Size = System::Drawing::Size(379, 28);
			this->cmbSelectStudent->TabIndex = 1;
			this->cmbSelectStudent->SelectedIndexChanged += gcnew System::EventHandler(this, &frmEnterGrade::comboBox1_SelectedIndexChanged);
			// 
			// cmbSelectCourse
			// 
			this->cmbSelectCourse->FormattingEnabled = true;
			this->cmbSelectCourse->Location = System::Drawing::Point(197, 70);
			this->cmbSelectCourse->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->cmbSelectCourse->Name = L"cmbSelectCourse";
			this->cmbSelectCourse->Size = System::Drawing::Size(312, 28);
			this->cmbSelectCourse->TabIndex = 2;
			// 
			// cmbGrade
			// 
			this->cmbGrade->FormattingEnabled = true;
			this->cmbGrade->Location = System::Drawing::Point(197, 213);
			this->cmbGrade->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->cmbGrade->Name = L"cmbGrade";
			this->cmbGrade->Size = System::Drawing::Size(247, 28);
			this->cmbGrade->TabIndex = 3;
			this->cmbGrade->SelectedIndexChanged += gcnew System::EventHandler(this, &frmEnterGrade::cmbGrade_SelectedIndexChanged);
			// 
			// cmbSemester
			// 
			this->cmbSemester->FormattingEnabled = true;
			this->cmbSemester->Location = System::Drawing::Point(197, 332);
			this->cmbSemester->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->cmbSemester->Name = L"cmbSemester";
			this->cmbSemester->Size = System::Drawing::Size(190, 28);
			this->cmbSemester->TabIndex = 4;
			// 
			// txtGradePoints
			// 
			this->txtGradePoints->Location = System::Drawing::Point(197, 265);
			this->txtGradePoints->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtGradePoints->Name = L"txtGradePoints";
			this->txtGradePoints->Size = System::Drawing::Size(124, 26);
			this->txtGradePoints->TabIndex = 5;
			// 
			// txtAcademicYear
			// 
			this->txtAcademicYear->Location = System::Drawing::Point(626, 336);
			this->txtAcademicYear->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtAcademicYear->Name = L"txtAcademicYear";
			this->txtAcademicYear->Size = System::Drawing::Size(124, 26);
			this->txtAcademicYear->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(38, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Select Student:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(68, 466);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(730, 187);
			this->dataGridView1->TabIndex = 8;
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(239, 407);
			this->btnSave->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(101, 37);
			this->btnSave->TabIndex = 9;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmEnterGrade::btnSave_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(441, 407);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(103, 37);
			this->btnCancel->TabIndex = 10;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmEnterGrade::btnCancel_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(63, 213);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 25);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Grade:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(436, 335);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(151, 25);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Academic Year:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(38, 264);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(131, 25);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Grade Points:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(63, 335);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 25);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Semester:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label7->Location = System::Drawing::Point(38, 69);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(142, 25);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Select Course:";
			// 
			// frmEnterGrade
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::YellowGreen;
			this->ClientSize = System::Drawing::Size(869, 684);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtAcademicYear);
			this->Controls->Add(this->txtGradePoints);
			this->Controls->Add(this->cmbSemester);
			this->Controls->Add(this->cmbGrade);
			this->Controls->Add(this->cmbSelectCourse);
			this->Controls->Add(this->cmbSelectStudent);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"frmEnterGrade";
			this->Text = L"Grades Entrance";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private:
		void LoadCourses() {
			try {
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
					"SELECT c.ID, CONCAT(c.CourseCode, ' - ', c.CourseTitle) AS CourseName " +
					"FROM courses c ORDER BY c.CourseCode", sqlConn);
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

		void LoadStudents() {
			try {
				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
					"SELECT s.ID, CONCAT(s.StudentID, ' - ', u.FirstName, ' ', u.LastName) AS StudentName " +
					"FROM students s INNER JOIN users u ON s.UserID = u.ID " +
					"WHERE s.status = 'active' ORDER BY s.StudentID", sqlConn);
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

		void LoadSemesters() {
			cmbSemester->Items->Clear();
			cmbSemester->Items->Add("First Semester");
			cmbSemester->Items->Add("Second Semester");
			cmbSemester->Items->Add("Summer Session");
		}

		void LoadGrades() {
			try {
				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlDT->Clear();
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
					"SELECT g.ID, s.StudentID, u.FirstName, u.LastName, c.CourseCode, c.CourseTitle, " +
					"g.Grade, g.GradePoints, g.Semester, g.AcademicYear, g.DateEntered " +
					"FROM grades g " +
					"INNER JOIN students s ON g.StudentID = s.ID " +
					"INNER JOIN users u ON s.UserID = u.ID " +
					"INNER JOIN courses c ON g.CourseID = c.ID " +
					"ORDER BY g.DateEntered DESC", sqlConn);
				da->Fill(sqlDT);
				dataGridView1->DataSource = sqlDT;
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading grades: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		double GetGradePoints(String^ grade) {
			if (grade == "A+") return 4.0;
			else if (grade == "A") return 4.0;
			else if (grade == "B+") return 3.5;
			else if (grade == "B") return 3.0;
			else if (grade == "C+") return 2.5;
			else if (grade == "C") return 2.0;
			else if (grade == "D+") return 1.5;
			else if (grade == "D") return 1.0;
			else return 0.0;
		}
		System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
			if (cmbSelectStudent->SelectedIndex == -1 || cmbSelectCourse->SelectedIndex == -1) {
				MessageBox::Show("Please select student and course", "Validation Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			if (cmbGrade->SelectedIndex == -1 || cmbSemester->SelectedIndex == -1) {
				MessageBox::Show("Please select grade and semester", "Validation Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ academicYear = txtAcademicYear->Text->Trim();
			if (academicYear == "") {
				MessageBox::Show("Please enter academic year", "Validation Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			try {
				int studentID = Convert::ToInt32(cmbSelectStudent->SelectedValue);
				int courseID = Convert::ToInt32(cmbSelectCourse->SelectedValue);
				String^ grade = cmbGrade->Text;
				double gradePoints = GetGradePoints(grade);
				String^ semester = cmbSemester->Text;

				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;

				// Check if grade already exists
				sqlCmd->CommandText = "SELECT * FROM grades WHERE StudentID=@stID AND CourseID=@cID " +
					"AND Semester=@sem AND AcademicYear=@year";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@stID", studentID);
				sqlCmd->Parameters->AddWithValue("@cID", courseID);
				sqlCmd->Parameters->AddWithValue("@sem", semester);
				sqlCmd->Parameters->AddWithValue("@year", academicYear);
				sqlDR = sqlCmd->ExecuteReader();

				if (sqlDR->Read()) {
					MessageBox::Show("Grade already exists for this student in this course", "Duplicate Entry",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					sqlDR->Close();
					sqlConn->Close();
					return;
				}
				sqlDR->Close();

				// Insert grade
				sqlCmd->CommandText = "INSERT INTO grades(StudentID, CourseID, Grade, GradePoints, Semester, AcademicYear) " +
					"VALUES (@stID, @cID, @grade, @gradePoints, @sem, @year)";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@stID", studentID);
				sqlCmd->Parameters->AddWithValue("@cID", courseID);
				sqlCmd->Parameters->AddWithValue("@grade", grade);
				sqlCmd->Parameters->AddWithValue("@gradePoints", gradePoints);
				sqlCmd->Parameters->AddWithValue("@sem", semester);
				sqlCmd->Parameters->AddWithValue("@year", academicYear);
				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("Grade saved successfully", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				LoadGrades();
				ClearFields();
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			}
		}

		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			ClearFields();
			this->Close();
		}

		System::Void cmbGrade_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			if (cmbGrade->SelectedIndex != -1) {
				double points = GetGradePoints(cmbGrade->Text);
				txtGradePoints->Text = points.ToString("0.00");
			}
		}

		void ClearFields() {
			cmbSelectStudent->SelectedIndex = -1;
			cmbSelectCourse->SelectedIndex = -1;
			cmbGrade->SelectedIndex = -1;
			cmbSemester->SelectedIndex = -1;
			txtGradePoints->Text = "";
			txtAcademicYear->Text = "";
		}
};
}
