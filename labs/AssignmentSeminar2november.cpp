#include <iostream>

class Book {
	char* author;
	char* title;	// string also accepted
	int pages_nr;
	int* page_wordcount;
	bool online;

public:
	void set_author(char* author) {
		this->author = new char[strlen(author)] + 1;
		strcpy_s(this->author, strlen(author) + 1, author);
	}
	void set_title(char* title) {
		this->title = new char[strlen(title)] + 1;
		strcpy_s(this->title, strlen(title) + 1, title);
	}
	void set_pages_nr(int number) {
		this->pages_nr = number;
	}
	void set_page_wordcount(int* page_wordcount) {
		this->page_wordcount = new int[this->pages_nr];
		for (int i = 0; i < this->pages_nr; i++)
			this->page_wordcount[i] = page_wordcount[i];
	}
	void set_online(bool state) {
		this->online = state;
	}

	Book(char* author, char* title, int pages_nr, int* page_wordcount, bool online) {
		this->set_author(author);
		set_title(title);
		set_pages_nr(pages_nr);
		set_page_wordcount(page_wordcount);
		set_online(online);
	}
	Book(const Book& copied_book): 
		Book(copied_book.author, copied_book.title, copied_book.pages_nr, copied_book.page_wordcount, copied_book.online)
	{
		
	}
	~Book() {
		delete[] this->author;
		delete[] this->title;
		delete[] this->page_wordcount;
	}
};

int main() {
	int page_wordcount[10] = { 100, 200, 150, 200, 150, 220, 170, 180, 190, 40 };
	char author[] = "Feodor Dostoievski";
	char title[] = "Crima si pedeapsa";
	Book carte(author, title, 10, page_wordcount, true);
}