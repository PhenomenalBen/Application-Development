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
	/// Summary for frmRegisterCourse
	/// </summary>
	public ref class frmRegisterCourse : public System::Windows::Forms::Form
	{
	public:

		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ dtAvailable = gcnew DataTable();
		DataTable^ dtSelected = gcnew DataTable();
		String^ ConnectionStr = "server=localhost;port=4306;uid=root;pwd=;database=ahsesimis;";
		int currentStudentID = 0;
		int totalCredits = 0;
		int globalRegistrationID = 0;

		frmRegisterCourse(int studentID)
		{
			InitializeComponent();
			currentStudentID = studentID;
			LoadStudentInfo();
			LoadSemesters();
			InitializeSelectedCoursesTable();
			LoadAvailableCourses();
			LoadRegisteredCourses();
			InitializeDataGridView();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegisterCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblStudentInfo;
	private: System::Windows::Forms::DataGridView^ dgvAvailableCourses;
	private: System::Windows::Forms::Button^ btnAddSelected;
	private: System::Windows::Forms::Button^ btnRemoveSelected;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::DataGridView^ dgvSelectedCourses;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ cmbSemester;
	private: System::Windows::Forms::Label^ lblTotalCredits;
	private: System::Windows::Forms::TextBox^ txtAcademicYear;
	private: System::Windows::Forms::DataGridView^ dgvRegisteredCourses;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnDropCourse;
	private: System::Windows::Forms::Button^ btnClearSelection;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Label^ label3;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblStudentInfo = (gcnew System::Windows::Forms::Label());
			this->dgvAvailableCourses = (gcnew System::Windows::Forms::DataGridView());
			this->btnAddSelected = (gcnew System::Windows::Forms::Button());
			this->btnRemoveSelected = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->dgvSelectedCourses = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
			this->lblTotalCredits = (gcnew System::Windows::Forms::Label());
			this->txtAcademicYear = (gcnew System::Windows::Forms::TextBox());
			this->dgvRegisteredCourses = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnDropCourse = (gcnew System::Windows::Forms::Button());
			this->btnClearSelection = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAvailableCourses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSelectedCourses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRegisteredCourses))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(262, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(245, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course Registration";
			// 
			// lblStudentInfo
			// 
			this->lblStudentInfo->AutoSize = true;
			this->lblStudentInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentInfo->Location = System::Drawing::Point(54, 52);
			this->lblStudentInfo->Name = L"lblStudentInfo";
			this->lblStudentInfo->Size = System::Drawing::Size(116, 20);
			this->lblStudentInfo->TabIndex = 1;
			this->lblStudentInfo->Text = L"Student Info:";
			// 
			// dgvAvailableCourses
			// 
			this->dgvAvailableCourses->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvAvailableCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAvailableCourses->Location = System::Drawing::Point(54, 89);
			this->dgvAvailableCourses->Name = L"dgvAvailableCourses";
			this->dgvAvailableCourses->RowHeadersWidth = 51;
			this->dgvAvailableCourses->RowTemplate->Height = 24;
			this->dgvAvailableCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvAvailableCourses->Size = System::Drawing::Size(690, 150);
			this->dgvAvailableCourses->TabIndex = 2;
			// 
			// btnAddSelected
			// 
			this->btnAddSelected->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddSelected->Location = System::Drawing::Point(54, 245);
			this->btnAddSelected->Name = L"btnAddSelected";
			this->btnAddSelected->Size = System::Drawing::Size(214, 35);
			this->btnAddSelected->TabIndex = 3;
			this->btnAddSelected->Text = L"Add Selected Courses";
			this->btnAddSelected->UseVisualStyleBackColor = true;
			this->btnAddSelected->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnAddSelected_Click);
			// 
			// btnRemoveSelected
			// 
			this->btnRemoveSelected->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRemoveSelected->Location = System::Drawing::Point(324, 245);
			this->btnRemoveSelected->Name = L"btnRemoveSelected";
			this->btnRemoveSelected->Size = System::Drawing::Size(171, 35);
			this->btnRemoveSelected->TabIndex = 4;
			this->btnRemoveSelected->Text = L"Remove Selected";
			this->btnRemoveSelected->UseVisualStyleBackColor = true;
			this->btnRemoveSelected->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnRemoveSelected_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->Location = System::Drawing::Point(54, 589);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(188, 41);
			this->btnRegister->TabIndex = 5;
			this->btnRegister->Text = L"Register Courses";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnRegister_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(248, 589);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(104, 41);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnCancel_Click);
			// 
			// dgvSelectedCourses
			// 
			this->dgvSelectedCourses->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvSelectedCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSelectedCourses->Location = System::Drawing::Point(54, 286);
			this->dgvSelectedCourses->Name = L"dgvSelectedCourses";
			this->dgvSelectedCourses->RowHeadersWidth = 51;
			this->dgvSelectedCourses->RowTemplate->Height = 24;
			this->dgvSelectedCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvSelectedCourses->Size = System::Drawing::Size(690, 150);
			this->dgvSelectedCourses->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(54, 508);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(203, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Registration Semester:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(366, 456);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(141, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Academic Year:";
			// 
			// cmbSemester
			// 
			this->cmbSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSemester->FormattingEnabled = true;
			this->cmbSemester->Location = System::Drawing::Point(288, 508);
			this->cmbSemester->Name = L"cmbSemester";
			this->cmbSemester->Size = System::Drawing::Size(245, 24);
			this->cmbSemester->TabIndex = 11;
			// 
			// lblTotalCredits
			// 
			this->lblTotalCredits->AutoSize = true;
			this->lblTotalCredits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalCredits->Location = System::Drawing::Point(54, 456);
			this->lblTotalCredits->Name = L"lblTotalCredits";
			this->lblTotalCredits->Size = System::Drawing::Size(124, 20);
			this->lblTotalCredits->TabIndex = 12;
			this->lblTotalCredits->Text = L"Total Credits:";
			// 
			// txtAcademicYear
			// 
			this->txtAcademicYear->Location = System::Drawing::Point(545, 456);
			this->txtAcademicYear->Name = L"txtAcademicYear";
			this->txtAcademicYear->Size = System::Drawing::Size(154, 22);
			this->txtAcademicYear->TabIndex = 14;
			// 
			// dgvRegisteredCourses
			// 
			this->dgvRegisteredCourses->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvRegisteredCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRegisteredCourses->Location = System::Drawing::Point(54, 750);
			this->dgvRegisteredCourses->Name = L"dgvRegisteredCourses";
			this->dgvRegisteredCourses->RowHeadersWidth = 51;
			this->dgvRegisteredCourses->RowTemplate->Height = 24;
			this->dgvRegisteredCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRegisteredCourses->Size = System::Drawing::Size(690, 150);
			this->dgvRegisteredCourses->TabIndex = 15;
			this->dgvRegisteredCourses->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmRegisterCourse::dgvRegisteredCourses_CellClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(54, 676);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 20);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Registered Courses:";
			// 
			// btnDropCourse
			// 
			this->btnDropCourse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDropCourse->Location = System::Drawing::Point(576, 589);
			this->btnDropCourse->Name = L"btnDropCourse";
			this->btnDropCourse->Size = System::Drawing::Size(168, 41);
			this->btnDropCourse->TabIndex = 17;
			this->btnDropCourse->Text = L"Drop Course";
			this->btnDropCourse->UseVisualStyleBackColor = true;
			this->btnDropCourse->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnDropCourse_Click);
			// 
			// btnClearSelection
			// 
			this->btnClearSelection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClearSelection->Location = System::Drawing::Point(578, 245);
			this->btnClearSelection->Name = L"btnClearSelection";
			this->btnClearSelection->Size = System::Drawing::Size(166, 35);
			this->btnClearSelection->TabIndex = 18;
			this->btnClearSelection->Text = L"Clear Selection";
			this->btnClearSelection->UseVisualStyleBackColor = true;
			this->btnClearSelection->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnClearSelection_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(545, 508);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(154, 22);
			this->txtSearch->TabIndex = 19;
			this->txtSearch->Text = L"Search Course...";
			// 
			// btnSearch
			// 
			this->btnSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSearch->Location = System::Drawing::Point(564, 543);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(104, 35);
			this->btnSearch->TabIndex = 20;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &frmRegisterCourse::btnSearch_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(366, 508);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(140, 20);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Search Course:";
			// 
			// frmRegisterCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::RosyBrown;
			this->ClientSize = System::Drawing::Size(800, 950);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->btnClearSelection);
			this->Controls->Add(this->btnDropCourse);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dgvRegisteredCourses);
			this->Controls->Add(this->txtAcademicYear);
			this->Controls->Add(this->lblTotalCredits);
			this->Controls->Add(this->cmbSemester);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dgvSelectedCourses);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->btnRemoveSelected);
			this->Controls->Add(this->btnAddSelected);
			this->Controls->Add(this->dgvAvailableCourses);
			this->Controls->Add(this->lblStudentInfo);
			this->Controls->Add(this->label1);
			this->Name = L"frmRegisterCourse";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student Course Registration";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAvailableCourses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSelectedCourses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRegisteredCourses))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Database Operations
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

		void LoadSemesters() {
			try {
				cmbSemester->Items->Clear();
				cmbSemester->Items->Add("First Semester");
				cmbSemester->Items->Add("Second Semester");
				cmbSemester->Items->Add("Summer Session");
				cmbSemester->SelectedIndex = 0;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading semesters: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void InitializeSelectedCoursesTable() {
			try {
				dtSelected->Columns->Clear();
				dtSelected->Columns->Add("CourseID", int::typeid);
				dtSelected->Columns->Add("CourseCode", String::typeid);
				dtSelected->Columns->Add("CourseTitle", String::typeid);
				dtSelected->Columns->Add("Credits", int::typeid);
				dtSelected->Columns->Add("Semester", String::typeid);
				dgvSelectedCourses->DataSource = dtSelected;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error initializing selected courses table: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void LoadAvailableCourses() {
			try {
				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();

				// Get student's level and programme
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT Level, ProgrammeID FROM students WHERE ID = @id";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
				sqlDR = sqlCmd->ExecuteReader();

				int studentLevel = 0;
				int progID = 0;
				if (sqlDR->Read()) {
					studentLevel = Convert::ToInt32(sqlDR["Level"]);
					progID = Convert::ToInt32(sqlDR["ProgrammeID"]);
				}
				sqlDR->Close();

				// Load courses for student's level and programme
				String^ query = "SELECT c.ID as CourseID, c.CourseCode, c.CourseTitle, c.CourseCredit as Credits, c.Semester, " +
					"p.Programme " +
					"FROM courses c " +
					"INNER JOIN programmes p ON c.Programme = p.ID " +
					"WHERE c.Level = @level AND c.Programme = @prog " +
					"AND c.ID NOT IN (SELECT CourseID FROM student_courses WHERE StudentID = @studentID AND Status = 'Registered') " +
					"ORDER BY c.Semester, c.CourseCode";

				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(query, sqlConn);
				da->SelectCommand->Parameters->AddWithValue("@level", studentLevel);
				da->SelectCommand->Parameters->AddWithValue("@prog", progID);
				da->SelectCommand->Parameters->AddWithValue("@studentID", currentStudentID);

				dtAvailable->Clear();
				da->Fill(dtAvailable);
				dgvAvailableCourses->DataSource = dtAvailable;
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading available courses: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void LoadRegisteredCourses() {
			try {
				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();

				String^ query = "SELECT sc.ID as RegistrationID, c.CourseCode, c.CourseTitle, " +
					"c.CourseCredit as Credits, sc.Semester, sc.AcademicYear, sc.RegistrationDate, sc.Status " +
					"FROM student_courses sc " +
					"INNER JOIN courses c ON sc.CourseID = c.ID " +
					"WHERE sc.StudentID = @studentID " +
					"ORDER BY sc.AcademicYear DESC, sc.Semester, c.CourseCode";

				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(query, sqlConn);
				da->SelectCommand->Parameters->AddWithValue("@studentID", currentStudentID);

				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvRegisteredCourses->DataSource = dt;
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading registered courses: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void InitializeDataGridView() {
			dgvAvailableCourses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvSelectedCourses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvRegisteredCourses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		}
#pragma endregion

#pragma region Event Handlers
	private:
		System::Void btnAddSelected_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (dgvAvailableCourses->SelectedRows->Count == 0) {
					MessageBox::Show("Please select a course to add", "Selection Required",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				String^ semester = cmbSemester->Text;
				if (semester->Trim() == "") {
					MessageBox::Show("Please select a semester first", "Semester Required",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				for each (DataGridViewRow ^ row in dgvAvailableCourses->SelectedRows) {
					int courseID = Convert::ToInt32(row->Cells["CourseID"]->Value);

					// Check if already added
					bool exists = false;
					for each (DataRow ^ dr in dtSelected->Rows) {
						if (Convert::ToInt32(dr["CourseID"]) == courseID) {
							exists = true;
							break;
						}
					}

					if (!exists) {
						DataRow^ newRow = dtSelected->NewRow();
						newRow["CourseID"] = row->Cells["CourseID"]->Value;
						newRow["CourseCode"] = row->Cells["CourseCode"]->Value;
						newRow["CourseTitle"] = row->Cells["CourseTitle"]->Value;
						newRow["Credits"] = row->Cells["Credits"]->Value;
						newRow["Semester"] = semester;
						dtSelected->Rows->Add(newRow);

						totalCredits += Convert::ToInt32(row->Cells["Credits"]->Value);
					}
				}

				UpdateTotalCredits();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error adding course: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnRemoveSelected_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (dgvSelectedCourses->SelectedRows->Count == 0) {
					MessageBox::Show("Please select a course to remove", "Selection Required",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				for each (DataGridViewRow ^ row in dgvSelectedCourses->SelectedRows) {
					totalCredits -= Convert::ToInt32(row->Cells["Credits"]->Value);
					dgvSelectedCourses->Rows->Remove(row);
				}

				UpdateTotalCredits();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error removing course: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (dtSelected->Rows->Count == 0) {
					MessageBox::Show("Please select at least one course", "No Courses Selected",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				if (cmbSemester->SelectedIndex == -1 || txtAcademicYear->Text->Trim() == "") {
					MessageBox::Show("Please select semester and enter academic year", "Validation Error",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				String^ semester = cmbSemester->Text;
				String^ academicYear = txtAcademicYear->Text->Trim();

				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;

				int successCount = 0;
				int duplicateCount = 0;

				for each (DataRow ^ row in dtSelected->Rows) {
					int courseID = Convert::ToInt32(row["CourseID"]);

					// Check if already registered
					sqlCmd->CommandText = "SELECT * FROM student_courses WHERE StudentID=@stID AND CourseID=@cID " +
						"AND Semester=@sem AND AcademicYear=@year AND Status='Registered'";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@stID", currentStudentID);
					sqlCmd->Parameters->AddWithValue("@cID", courseID);
					sqlCmd->Parameters->AddWithValue("@sem", semester);
					sqlCmd->Parameters->AddWithValue("@year", academicYear);
					sqlDR = sqlCmd->ExecuteReader();

					if (!sqlDR->Read()) {
						sqlDR->Close();

						// Register course
						sqlCmd->CommandText = "INSERT INTO student_courses(StudentID, CourseID, Semester, AcademicYear, Status) " +
							"VALUES (@stID, @cID, @sem, @year, 'Registered')";
						sqlCmd->Parameters->Clear();
						sqlCmd->Parameters->AddWithValue("@stID", currentStudentID);
						sqlCmd->Parameters->AddWithValue("@cID", courseID);
						sqlCmd->Parameters->AddWithValue("@sem", semester);
						sqlCmd->Parameters->AddWithValue("@year", academicYear);
						sqlCmd->ExecuteNonQuery();
						successCount++;
					}
					else {
						sqlDR->Close();
						duplicateCount++;
					}
				}

				sqlConn->Close();

				String^ message = "";
				if (successCount > 0) {
					message = "Successfully registered " + successCount + " course(s)";
					if (duplicateCount > 0) {
						message += ". " + duplicateCount + " course(s) were already registered.";
					}
					MessageBox::Show(message, "Success",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else if (duplicateCount > 0) {
					MessageBox::Show("All selected courses were already registered", "Information",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}

				// Refresh data
				ClearSelection();
				LoadAvailableCourses();
				LoadRegisteredCourses();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			}
		}

		System::Void btnDropCourse_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (globalRegistrationID == 0) {
					MessageBox::Show("No course selected for dropping", "Selection Required",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				if (MessageBox::Show("Are you sure you want to drop this course?", "Confirm Drop",
					MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					sqlConn->ConnectionString = ConnectionStr;
					sqlConn->Open();
					sqlCmd->Connection = sqlConn;

					sqlCmd->CommandText = "UPDATE student_courses SET Status='Dropped' WHERE ID=@id AND StudentID=@studentID";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@id", globalRegistrationID);
					sqlCmd->Parameters->AddWithValue("@studentID", currentStudentID);

					int rowsAffected = sqlCmd->ExecuteNonQuery();
					sqlConn->Close();

					if (rowsAffected > 0) {
						MessageBox::Show("Course dropped successfully", "Success",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
						LoadAvailableCourses();
						LoadRegisteredCourses();
						globalRegistrationID = 0;
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error dropping course: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
			}
		}

		System::Void btnClearSelection_Click(System::Object^ sender, System::EventArgs^ e) {
			ClearSelection();
		}

		System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				String^ searchText = txtSearch->Text->Trim();
				if (searchText == "" || searchText == "Search Course...") {
					LoadAvailableCourses();
					return;
				}

				if (sqlConn->State == ConnectionState::Open) sqlConn->Close();
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();

				// Get student's level and programme
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT Level, ProgrammeID FROM students WHERE ID = @id";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@id", currentStudentID);
				sqlDR = sqlCmd->ExecuteReader();

				int studentLevel = 0;
				int progID = 0;
				if (sqlDR->Read()) {
					studentLevel = Convert::ToInt32(sqlDR["Level"]);
					progID = Convert::ToInt32(sqlDR["ProgrammeID"]);
				}
				sqlDR->Close();

				// Search courses
				String^ query = "SELECT c.ID as CourseID, c.CourseCode, c.CourseTitle, c.CourseCredit as Credits, c.Semester, " +
					"p.Programme " +
					"FROM courses c " +
					"INNER JOIN programmes p ON c.Programme = p.ID " +
					"WHERE c.Level = @level AND c.Programme = @prog " +
					"AND (c.CourseCode LIKE @search OR c.CourseTitle LIKE @search) " +
					"AND c.ID NOT IN (SELECT CourseID FROM student_courses WHERE StudentID = @studentID AND Status = 'Registered') " +
					"ORDER BY c.Semester, c.CourseCode";

				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(query, sqlConn);
				da->SelectCommand->Parameters->AddWithValue("@level", studentLevel);
				da->SelectCommand->Parameters->AddWithValue("@prog", progID);
				da->SelectCommand->Parameters->AddWithValue("@studentID", currentStudentID);
				da->SelectCommand->Parameters->AddWithValue("@search", "%" + searchText + "%");

				dtAvailable->Clear();
				da->Fill(dtAvailable);
				dgvAvailableCourses->DataSource = dtAvailable;
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error searching courses: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void dgvRegisteredCourses_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
			try {
				if (e->RowIndex >= 0) {
					DataGridViewRow^ row = dgvRegisteredCourses->Rows[e->RowIndex];
					globalRegistrationID = Convert::ToInt32(row->Cells["RegistrationID"]->Value);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error selecting course: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
#pragma endregion

#pragma region Helper Methods
	private:
		void UpdateTotalCredits() {
			lblTotalCredits->Text = "Total Credits: " + totalCredits.ToString();
		}

		void ClearSelection() {
			dtSelected->Clear();
			totalCredits = 0;
			UpdateTotalCredits();
			globalRegistrationID = 0;
		}
#pragma endregion
	};
}