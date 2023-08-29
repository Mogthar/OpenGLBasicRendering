#pragma once
class OWindow
{
public:
	OWindow();
	~OWindow();
	void onDestroy();
	void onClose();
	bool isClosed();
private:
	void* m_handle = nullptr;

};

