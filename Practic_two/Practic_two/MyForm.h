#pragma once
#include <Windows.h>
#include <math.h>

namespace Practictwo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::ComboBox^ comboBox6;
	private: System::Windows::Forms::ComboBox^ comboBox7;
	private: System::Windows::Forms::ComboBox^ comboBox8;
	private: System::Windows::Forms::ComboBox^ comboBox9;
	private: System::Windows::Forms::ComboBox^ comboBox10;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::ComboBox^ comboBox11;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::ComboBox^ comboBox12;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ComboBox^ comboBox13;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::ComboBox^ comboBox14;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::ComboBox^ comboBox15;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: void Paint_Star(int x, int y, int Cx, int Cy, System::Object^ sender, System::EventArgs^ e, float angle, int size, float angle_star)
	{
		Graphics^ Графика = pictureBox1->CreateGraphics();
		array<Point>^ p1;//Создаём массив координат для объекта "Звезда"
		p1 = gcnew array<Point>(9);
		array<Point>^ p2;//Создаём массив координат для объекта "Звезда"
		p2 = gcnew array<Point>(9);
		//присваиваем координаты, обновляя их при рисовании
		p1[0] = Drawing::Point((-12 * size * sin(angle)) + int(x) + Cx, 0 * size * sin(angle) + int(y) + Cy);
		p1[1] = Drawing::Point((-2 * size * sin(angle))  + int(x) + Cx, 3 * size * sin(angle) + int(y) + Cy);
		p1[2] = Drawing::Point((0 * size * sin(angle)) + int(x) + Cx, 12 * size * sin(angle) + int(y) + Cy);
		p1[3] = Drawing::Point((2 * size * sin(angle)) + int(x) + Cx, 3 * size * sin(angle) + int(y) + Cy);
		p1[4] = Drawing::Point((12 * size * sin(angle)) + int(x) + Cx, 0 * size * sin(angle) + int(y) + Cy);
		p1[5] = Drawing::Point((2 * size * sin(angle)) + int(x) + Cx, -3 * size * sin(angle) + int(y) + Cy);
		p1[6] = Drawing::Point((0 * size * sin(angle)) + int(x) + Cx, -12 * size * sin(angle) + int(y) + Cy);
		p1[7] = Drawing::Point((-2 * size * sin(angle)) + int(x) + Cx, -3 * size * sin(angle) + int(y) + Cy);
		p1[8] = Drawing::Point((-12 * size * sin(angle)) + int(x) + Cx, 0 * size * sin(angle) + int(y) + Cy);
		//вращение фигуры
		for (int i = 0; i < 9; i++) {
			p2[i] = Drawing::Point((p1[i].X - int(x) - Cx) * cos(angle_star) - (p1[i].Y - int(y) - Cy) * sin(angle_star) + int(x) + Cx, (p1[i].X - int(x) - Cx) * sin(angle_star) + (p1[i].Y - int(y) - Cy) * cos(angle_star) + int(y) + Cy);
		}
		Color color = comboBox3_SelectedIndexChanged(sender, e);//заливка
		Color color1 = comboBox4_SelectedIndexChanged(sender, e);//контур
		SolidBrush^ brush = gcnew SolidBrush(color);//создаём заливку с данным цветом
		Pen^ skyBluePen = gcnew Pen(color1, comboBox5_SelectedIndexChanged(sender, e));//инициаллизируем перо с этим цветом
		if (comboBox15_SelectedIndexChanged(sender, e) == 1) {
			skyBluePen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
		}
		if (comboBox15_SelectedIndexChanged(sender, e) == 2) {
			skyBluePen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
		}
		Графика->DrawLines(skyBluePen, p2);
		Графика->FillPolygon(brush, p2);//заливаем объект
		Графика->RotateTransform(angle);
		
	}
	private: void Paint_Graphic(int cX, int cY, int x, int y, array<Point>^ p, System::Object^ sender, System::EventArgs^ e)
	{
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Color color = Color::FromArgb(int(255), int(0), int(0), int(0));//черный
		Color color1 = comboBox2_SelectedIndexChanged(sender, e);
		Графика->Clear(comboBox13_SelectedIndexChanged(sender, e));

		Pen^ pen = gcnew Pen(color1, comboBox6_SelectedIndexChanged(sender, e));//инициаллизируем перо с этим цветом
		Pen^ pen_axis = gcnew Pen(comboBox14_SelectedIndexChanged(sender, e), comboBox6_SelectedIndexChanged(sender, e));//инициаллизируем перо с этим цветом
		if (comboBox7_SelectedIndexChanged(sender, e) == 1) {
			pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
		}
		if (comboBox7_SelectedIndexChanged(sender, e) == 2) {
			pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
		}
		Графика->DrawLines(pen, p); // траектория
		//рисуем оси x и y
		Графика->DrawLine(pen_axis, 0, 195, 386, 195);
		Графика->DrawLine(pen_axis, 193, 0, 193, 415);
	}
	private:
		/// Обязательная переменная конструктора.
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->comboBox11 = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->comboBox12 = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->comboBox13 = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox14 = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->comboBox15 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(515, 500);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(184, 521);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Сверху вниз", L"Снизу вверх" });
			this->comboBox1->Location = System::Drawing::Point(832, 137);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(221, 23);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"Направление";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(832, 307);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(246, 247);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Белый", L"Красный", L"Синий", L"Зелёный", L"Жёлтый",
					L"Чёрный"
			});
			this->comboBox2->Location = System::Drawing::Point(543, 134);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(221, 23);
			this->comboBox2->TabIndex = 6;
			this->comboBox2->Text = L"Цвет траектории";
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Белый", L"Красный", L"Синий", L"Зелёный", L"Жёлтый",
					L"Чёрный"
			});
			this->comboBox3->Location = System::Drawing::Point(543, 185);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(221, 23);
			this->comboBox3->TabIndex = 7;
			this->comboBox3->Text = L"Цвет заливки";
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Белый", L"Красный", L"Синий", L"Зелёный", L"Жёлтый",
					L"Чёрный"
			});
			this->comboBox4->Location = System::Drawing::Point(543, 236);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(221, 23);
			this->comboBox4->TabIndex = 8;
			this->comboBox4->Text = L"Цвет контура";
			// 
			// comboBox5
			// 
			this->comboBox5->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->comboBox5->Location = System::Drawing::Point(543, 287);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(221, 23);
			this->comboBox5->TabIndex = 9;
			this->comboBox5->Text = L"Толщина контура";
			// 
			// comboBox6
			// 
			this->comboBox6->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->comboBox6->Location = System::Drawing::Point(543, 338);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(221, 23);
			this->comboBox6->TabIndex = 10;
			this->comboBox6->Text = L"Толщина траектории";
			// 
			// comboBox7
			// 
			this->comboBox7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->comboBox7->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Сплошная", L"С длинными штрихами", L"С короткими штрихами" });
			this->comboBox7->Location = System::Drawing::Point(543, 389);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(221, 23);
			this->comboBox7->TabIndex = 11;
			this->comboBox7->Text = L"Вид линии траектории";
			// 
			// comboBox8
			// 
			this->comboBox8->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->comboBox8->Location = System::Drawing::Point(832, 239);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(221, 23);
			this->comboBox8->TabIndex = 12;
			this->comboBox8->Text = L"Период";
			// 
			// comboBox9
			// 
			this->comboBox9->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->comboBox9->Location = System::Drawing::Point(543, 489);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(221, 23);
			this->comboBox9->TabIndex = 13;
			this->comboBox9->Text = L"Размер объекта";
			// 
			// comboBox10
			// 
			this->comboBox10->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox10->FormattingEnabled = true;
			this->comboBox10->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"0,25x", L"0,5x", L"0,75x", L"1x", L"1,25x",
					L"1,5x", L"1,75x", L"2,x", L"10x"
			});
			this->comboBox10->Location = System::Drawing::Point(832, 191);
			this->comboBox10->Name = L"comboBox10";
			this->comboBox10->Size = System::Drawing::Size(221, 23);
			this->comboBox10->TabIndex = 14;
			this->comboBox10->Text = L"Скорость объекта";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(832, 117);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 17);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Направление";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(543, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 17);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Цвет траектории";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(543, 165);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 17);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Цвет заливки";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(543, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 17);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Цвет контура";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(543, 267);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(155, 17);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Толщина контура";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(543, 318);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(183, 17);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Толщина траектории";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(543, 369);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(196, 17);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Вид линии траектории";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(832, 219);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 17);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Период";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(543, 469);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(141, 17);
			this->label9->TabIndex = 23;
			this->label9->Text = L"Размер объекта";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(832, 171);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(155, 17);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Скорость объекта";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(832, 284);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(168, 17);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Заданная функция";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(832, 16);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(44, 17);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Шаг";
			// 
			// comboBox11
			// 
			this->comboBox11->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox11->FormattingEnabled = true;
			this->comboBox11->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0,05", L"0,1", L"0,15", L"0,2" });
			this->comboBox11->Location = System::Drawing::Point(832, 33);
			this->comboBox11->Name = L"comboBox11";
			this->comboBox11->Size = System::Drawing::Size(221, 23);
			this->comboBox11->TabIndex = 27;
			this->comboBox11->Text = L"Шаг";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(832, 66);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(221, 17);
			this->label13->TabIndex = 28;
			this->label13->Text = L"Коэффициент отклонения";
			// 
			// comboBox12
			// 
			this->comboBox12->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox12->FormattingEnabled = true;
			this->comboBox12->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"-225", L"-115", L"-45", L"45", L"115", L"225" });
			this->comboBox12->Location = System::Drawing::Point(832, 84);
			this->comboBox12->Name = L"comboBox12";
			this->comboBox12->Size = System::Drawing::Size(221, 23);
			this->comboBox12->TabIndex = 29;
			this->comboBox12->Text = L"Коэффициент отклонения";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(543, 16);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(96, 17);
			this->label14->TabIndex = 30;
			this->label14->Text = L"Цвет фона";
			// 
			// comboBox13
			// 
			this->comboBox13->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox13->FormattingEnabled = true;
			this->comboBox13->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Белый", L"Красный", L"Синий", L"Зелёный", L"Жёлтый",
					L"Чёрный"
			});
			this->comboBox13->Location = System::Drawing::Point(543, 33);
			this->comboBox13->Name = L"comboBox13";
			this->comboBox13->Size = System::Drawing::Size(221, 23);
			this->comboBox13->TabIndex = 31;
			this->comboBox13->Text = L"Цвет фона";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(543, 64);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(89, 17);
			this->label15->TabIndex = 32;
			this->label15->Text = L"Цвет осей";
			// 
			// comboBox14
			// 
			this->comboBox14->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox14->FormattingEnabled = true;
			this->comboBox14->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Белый", L"Красный", L"Синий", L"Зелёный", L"Жёлтый",
					L"Чёрный"
			});
			this->comboBox14->Location = System::Drawing::Point(543, 84);
			this->comboBox14->Name = L"comboBox14";
			this->comboBox14->Size = System::Drawing::Size(221, 23);
			this->comboBox14->TabIndex = 33;
			this->comboBox14->Text = L"Цвет осей";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Muller Bold Italic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(543, 420);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(166, 17);
			this->label16->TabIndex = 34;
			this->label16->Text = L"Вид линии объекта";
			// 
			// comboBox15
			// 
			this->comboBox15->Font = (gcnew System::Drawing::Font(L"Muller Regular Italic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox15->FormattingEnabled = true;
			this->comboBox15->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Сплошная", L"С длинными штрихами", L"С короткими штрихами" });
			this->comboBox15->Location = System::Drawing::Point(543, 440);
			this->comboBox15->Name = L"comboBox15";
			this->comboBox15->Size = System::Drawing::Size(221, 23);
			this->comboBox15->TabIndex = 35;
			this->comboBox15->Text = L"Вид линии объекта";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1108, 581);
			this->Controls->Add(this->comboBox15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->comboBox14);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->comboBox13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->comboBox12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->comboBox11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox10);
			this->Controls->Add(this->comboBox9);
			this->Controls->Add(this->comboBox8);
			this->Controls->Add(this->comboBox7);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Циссоида Диокла";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int size = comboBox9_SelectedIndexChanged(sender, e);
		int period = comboBox8_SelectedIndexChanged(sender, e);
		int speed = 20 / comboBox10_SelectedIndexChanged(sender, e);
		double InitT = 1.7, LastT = 4.4, Step = comboBox11_SelectedIndexChanged(sender, e), angle = 1.7;
		double x, y;
		int cX = 193, cY = 195; // центр 
		int k = comboBox12_SelectedIndexChanged(sender, e); // коэффициент отклонения
		while (period != 0) {
			float angle_star = 0;
			float step_star = 0.17;
			int i = 0; // количество точек прорисовки
			array<Point>^ p;
			p = gcnew array<Point>(64); // точки для прорисовки (LastT/Step)
			if (comboBox1_SelectedIndexChanged(sender, e) == true) {
				InitT = 1.7, LastT = 4.4, Step = comboBox11_SelectedIndexChanged(sender, e), angle = InitT;
				while (angle <= LastT)
				{
					x = (2 * k * pow(tan(angle), 2)) / (1 + pow(tan(angle), 2));
					y = (2 * k * pow(tan(angle), 3)) / (1 + pow(tan(angle), 2));
					p[i] = Drawing::Point(cX + int(x), cY + int(y)); // расчет очередной точки траектории
					Paint_Graphic(cX, cY, x, y, p, sender, e);
					Paint_Star(x, y, cX, cY, sender, e, angle, size, angle_star);
					angle_star += step_star;
					angle += Step;
					::Sleep(speed); //время приостановки прорисовки
					i++;
				}
			}
			else {
				InitT = 4.4, LastT = 1.7, Step = comboBox11_SelectedIndexChanged(sender, e) * -1, angle = InitT;
				while (angle >= LastT)
				{
					x = (2 * k * pow(tan(angle), 2)) / (1 + pow(tan(angle), 2));
					y = (2 * k * pow(tan(angle), 3)) / (1 + pow(tan(angle), 2));
					p[i] = Drawing::Point(cX + int(x), cY + int(y)); // расчет очередной точки траектории
					Paint_Graphic(cX, cY, x, y, p, sender, e);
					Paint_Star(x, y, cX, cY, sender, e, angle, size, angle_star);
					angle_star += step_star;
					angle += Step;
					::Sleep(speed); //время приостановки прорисовки
					i++;
				}
			}
			period--;
		}
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Графика->Clear(comboBox13_SelectedIndexChanged(sender, e));
	}
	//направление
	bool comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		bool route = true;
		switch (comboBox1->SelectedIndex)
		{
		case 0: route = true; break;
		case 1: route = false; break;
		}
		return route;
	}
	//цвет траектории
	Color comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Color color;
		switch (comboBox2->SelectedIndex)
		{
		case 0: color = Color::FromArgb(int(255), int(255), int(255), int(255)); break;//белый
		case 1: color = Color::FromArgb(int(255), int(255), int(0), int(0)); break;//красный
		case 2: color = Color::FromArgb(int(255), int(0), int(0), int(255)); break;//синий
		case 3: color = Color::FromArgb(int(255), int(0), int(255), int(0)); break;//зеленый
		case 4: color = Color::FromArgb(int(255), int(255), int(255), int(0)); break;//желтый
		case 5: color = Color::FromArgb(int(255), int(0), int(0), int(0)); break;//черный
		}
		return color;
	}
	//цвет заливки объекта
	Color comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Color color;
		switch (comboBox3->SelectedIndex)
		{
		case 0: color = Color::FromArgb(int(127), int(255), int(255), int(255)); break;//белый
		case 1: color = Color::FromArgb(int(127), int(255), int(0), int(0)); break;//красный
		case 2: color = Color::FromArgb(int(127), int(0), int(0), int(255)); break;//синий
		case 3: color = Color::FromArgb(int(127), int(0), int(255), int(0)); break;//зеленый
		case 4: color = Color::FromArgb(int(127), int(255), int(255), int(0)); break;//желтый
		case 5: color = Color::FromArgb(int(255), int(0), int(0), int(0)); break;//черный
		}
		return color;
	}
	//цвет контура объекта
	Color comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Color color;
		switch (comboBox4->SelectedIndex)
		{
		case 0: color = Color::FromArgb(int(255), int(255), int(255), int(255)); break;//белый
		case 1: color = Color::FromArgb(int(255), int(255), int(0), int(0)); break;//красный
		case 2: color = Color::FromArgb(int(255), int(0), int(0), int(255)); break;//синий
		case 3: color = Color::FromArgb(int(255), int(0), int(255), int(0)); break;//зеленый
		case 4: color = Color::FromArgb(int(255), int(255), int(255), int(0)); break;//желтый
		case 5: color = Color::FromArgb(int(255), int(0), int(0), int(0)); break;//черный
		}
		return color;
	}
	//толщина контура
	int comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int width = 0;
		switch (comboBox5->SelectedIndex)
		{
		case 0: width = 1; break;
		case 1: width = 2; break;
		case 2: width = 3; break;
		case 3: width = 4; break;
		case 4: width = 5; break;
		}
		return width;
	}
	//толщина траектории
	int comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int width = 0;
		switch (comboBox6->SelectedIndex)
		{
		case 0: width = 1; break;
		case 1: width = 2; break;
		case 2: width = 3; break;
		case 3: width = 4; break;
		case 4: width = 5; break;
		}
		return width;
	}
	//стиль пера траектории
	int comboBox7_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int style = 0;
		switch (comboBox7->SelectedIndex)
		{
		case 0: style = 0; break;
		case 1: style = 1; break;
		case 2: style = 2; break;
		}
		return style;
	}
	//период
	int comboBox8_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int period = 0;
		switch (comboBox8->SelectedIndex)
		{
		case 0: period = 1; break;
		case 1: period = 2; break;
		case 2: period = 3; break;
		case 3: period = 4; break;
		case 4: period = 5; break;
		}
		return period;
	}
	//размер
	int comboBox9_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int size = 0;
		switch (comboBox9->SelectedIndex)
		{
		case 0: size = 1; break;
		case 1: size = 2; break;
		case 2: size = 3; break;
		case 3: size = 4; break;
		case 4: size = 5; break;
		}
		return size;
	}
	//скорость объекта
	float comboBox10_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		float speed = 0;
		switch (comboBox10->SelectedIndex)
		{
		case 0: speed = 0.25; break;
		case 1: speed = 0.5; break;
		case 2: speed = 0.75; break;
		case 3: speed = 1.0; break;
		case 4: speed = 1.25; break;
		case 5: speed = 1.5; break;
		case 6: speed = 1.75; break;
		case 7: speed = 2.0; break;
		case 8: speed = 10.0; break;
		}
		return speed;
	}
	//шаг
	float comboBox11_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		float step = 0;
		switch (comboBox11->SelectedIndex)
		{
		case 0: step = 0.05; break;
		case 1: step = 0.1; break;
		case 2: step = 0.15; break;
		case 3: step = 0.2; break;
		}
		return step;
	}
	//коэф. отклонения
	int comboBox12_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int coef = 0;
		switch (comboBox12->SelectedIndex)
		{
		case 0: coef = -225; break;
		case 1: coef = -115; break;
		case 2: coef = -45; break;
		case 3: coef = 45; break;
		case 4: coef = 115; break;
		case 5: coef = 225; break;
		}
		return coef;
	}
	//цвет фона
	Color comboBox13_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Color color;
		switch (comboBox13->SelectedIndex)
		{
		case 0: color = Color::FromArgb(int(255), int(255), int(255), int(255)); break;//белый
		case 1: color = Color::FromArgb(int(255), int(255), int(0), int(0)); break;//красный
		case 2: color = Color::FromArgb(int(255), int(0), int(0), int(255)); break;//синий
		case 3: color = Color::FromArgb(int(255), int(0), int(255), int(0)); break;//зеленый
		case 4: color = Color::FromArgb(int(255), int(255), int(255), int(0)); break;//желтый
		case 5: color = Color::FromArgb(int(255), int(0), int(0), int(0)); break;//черный
		}
		return color;
	}
    //цвет осей
	Color comboBox14_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Color color;
		switch (comboBox14->SelectedIndex)
		{
		case 0: color = Color::FromArgb(int(255), int(255), int(255), int(255)); break;//белый
		case 1: color = Color::FromArgb(int(255), int(255), int(0), int(0)); break;//красный
		case 2: color = Color::FromArgb(int(255), int(0), int(0), int(255)); break;//синий
		case 3: color = Color::FromArgb(int(255), int(0), int(255), int(0)); break;//зеленый
		case 4: color = Color::FromArgb(int(255), int(255), int(255), int(0)); break;//желтый
		case 5: color = Color::FromArgb(int(255), int(0), int(0), int(0)); break;//черный
		}
		return color;
	}
	//стиль линии объекта
	int comboBox15_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int style = 0;
		switch (comboBox15->SelectedIndex)
		{
		case 0: style = 0; break;
		case 1: style = 1; break;
		case 2: style = 2; break;
		}
		return style;
	}
};
}
