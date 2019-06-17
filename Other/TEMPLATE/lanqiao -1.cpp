#include <windows.h>

#define ID_TIMER    1
#define STRMAXLEN  25 //һ����ʾ�е���󳤶�
#define STRMINLEN  8  //һ����ʾ�е���С����

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
typedef struct tagCharChain //����������Ļ��һ����ʾ��,���Ǹ�˫���б�
{
        struct tagCharChain *prev; //�����ǰ��Ԫ��
        TCHAR  ch;                  //һ����ʾ���е�һ���ַ�
        struct tagCharChain *next; //����ĺ��Ԫ��
}CharChain, *pCharChain;

typedef struct tagCharColumn
{
        CharChain *head, *current, *point;
        int x, y, iStrLen; //��ʾ�еĿ�ʼ��ʾ��x,y����,iStrLen������еĳ���
        int iStopTimes, iMustStopTimes; //�Ѿ�ͣ�͵Ĵ����ͱ���ͣ�͵Ĵ���,����ͣ�͵Ĵ����������
}CharColumn, *pCharColumn;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        PSTR szCmdLine, int iCmdShow)
{
        static TCHAR szAppName[] = TEXT ("matrix") ;
        HWND            hwnd ;
        MSG            msg ;
        WNDCLASS    wndclass ;

        wndclass.style                = CS_HREDRAW | CS_VREDRAW ;
        wndclass.lpfnWndProc        = WndProc ;
        wndclass.cbClsExtra        = 0 ;
        wndclass.cbWndExtra        = 0 ;
        wndclass.hInstance        = hInstance ;
        wndclass.hIcon                = LoadIcon (NULL, IDI_APPLICATION) ;
        wndclass.hCursor        = LoadCursor (NULL, IDC_ARROW) ;
        wndclass.hbrBackground        = (HBRUSH) GetStockObject (BLACK_BRUSH);
        wndclass.lpszMenuName        = NULL ;
        wndclass.lpszClassName        = szAppName ;

        if(!RegisterClass (&wndclass))
        {
                MessageBox (NULL, TEXT (""), szAppName, MB_ICONERROR) ;
                return 0;
        }

        hwnd = CreateWindow (szAppName, NULL,
                WS_DLGFRAME | WS_THICKFRAME | WS_POPUP,
                0, 0,
                GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
                NULL, NULL, hInstance,
                NULL) ;

        ShowWindow (hwnd, SW_SHOWMAXIMIZED) ; //�����ʾ
        UpdateWindow (hwnd) ;
        ShowCursor(FALSE); //���������

        srand ((int) GetCurrentTime ()) ; //��ʼ�������������
        while (GetMessage (&msg, NULL, 0, 0))
        {
                TranslateMessage (&msg) ;
                DispatchMessage (&msg) ;
        }
        ShowCursor(TRUE); //��ʾ�����
        return msg.wParam ;
}

TCHAR randomChar() //����ַ���������
{
        return (TCHAR)(rand()%2+48); //�ַ�0��1
}

int init(CharColumn *cc, int cyScreen, int x) //��ʼ��
{
        int j;
        cc->iStrLen = rand()%(STRMAXLEN-STRMINLEN) + STRMINLEN; //��ʾ�еĳ���
        cc->x = x+3 ;        //��ʾ�еĿ�ʼ��ʾ��x����
        cc->y =rand()%3?rand()%cyScreen:0; //��ʾ�еĿ�ʼ��ʾ��y����
        cc->iMustStopTimes = rand()%6 ;
        cc->iStopTimes    = 0 ;
        cc->head = cc->current =
                (pCharChain)calloc(cc->iStrLen, sizeof(CharChain)); //������ʾ��
        for(j=0; j<cc->iStrLen-1; j++)
        {
                cc->current->prev = cc->point; //cc->pointһ����ʾ�е�ǰ��Ԫ��
                cc->current->ch  = '\0';
                cc->current->next = cc->current+1; //cc->current+1һ����ʾ�еĺ��Ԫ��
                cc->point          = cc->current++; //cc->point = cc->current; cc->current++;
        }
        cc->current->prev = cc->point; //���һ���ڵ�
        cc->current->ch  = '\0';
        cc->current->next = cc->head;
        cc->head->prev    = cc->current; //ͷ�ڵ��ǰһ��Ϊ���������һ��Ԫ��

        cc->current = cc->point = cc->head; //free��������ڴ�Ҫ��current������
        cc->head->ch = randomChar(); // ������ͷ�� Ԫ�����
        return 0;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
        HDC          hdc ;
        //ctn ����ȷ��һ����ʾ���Ƿ� ����ǰ��,����ȴ�������������ȴ��Ĵ���,ctn�ʹ���Ҫ����ǰ��
        int i, j, temp, ctn; //jΪһ����ʾ���г�����ͷ�������Ļ����ʾ��y����,temp��ɫ���ȵ���ɫ֮��
        static  HDC hdcMem;
        HFONT    hFont;
        static  HBITMAP hBitmap;
        static  int cxScreen, cyScreen; //��Ļ�Ŀ�� �߶�.
        static  int iFontWidth=10, iFontHeight=15, iColumnCount; //����Ŀ�� �߶�, ����
        static  CharColumn *ccChain;

        switch (message)
        {
        case WM_CREATE:
                cxScreen = GetSystemMetrics(SM_CXSCREEN) ; //��Ļ���
                cyScreen = GetSystemMetrics(SM_CYSCREEN) ;
                SetTimer (hwnd, ID_TIMER, 10, NULL) ;

                hdc = GetDC(hwnd);
                hdcMem = CreateCompatibleDC(hdc);
                hBitmap = CreateCompatibleBitmap(hdc, cxScreen, cyScreen);
                SelectObject(hdcMem, hBitmap);
                ReleaseDC(hwnd, hdc);
                //��������
                hFont = CreateFont(iFontHeight, iFontWidth-5, 0, 0, FW_BOLD, 0, 0, 0,
                        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                        DRAFT_QUALITY, FIXED_PITCH | FF_SWISS, TEXT("Fixedsys"));
                SelectObject(hdcMem, hFont);
                DeleteObject (hFont) ;
                SetBkMode(hdcMem, TRANSPARENT); //���ñ���ģʽΪ ͸��
                iColumnCount = cxScreen/(iFontWidth*3/2); //��Ļ����ʾ��ĸ�������

                ccChain = (pCharColumn)calloc(iColumnCount, sizeof(CharColumn));
                for(i=0; i<iColumnCount; i++)
                {
                        init(ccChain+i, cyScreen, (iFontWidth*3/2)*i);
                }
                return 0 ;

        case WM_TIMER:
                hdc = GetDC(hwnd);
                PatBlt (hdcMem, 0, 0, cxScreen, cyScreen, BLACKNESS) ; //���ڴ��豸ӳ��ˢ�ɺ�ɫ
                for(i=0; i<iColumnCount; i++)
                {
                        ctn = (ccChain+i)->iStopTimes++ > (ccChain+i)->iMustStopTimes;
                        //
                        (ccChain+i)->point = (ccChain+i)->head; //point���ڱ���������ʾ��

                        //��һ���ַ���ʾΪ ��ɫ
                        SetTextColor(hdcMem, RGB(255, 255, 255));
                        TextOut(hdcMem, (ccChain+i)->x, (ccChain+i)->y, &((ccChain+i)->point->ch), 1);
                        j = (ccChain+i)->y;
                        (ccChain+i)->point = (ccChain+i)->point->next;
                        //����������ʾ��,�������ʾ������ַ�����������ʾ
                        temp = 0 ; //temp��ɫ���ȵ���ɫ֮��
                        while((ccChain+i)->point != (ccChain+i)->head && (ccChain+i)->point->ch)
                        {
                                SetTextColor(hdcMem, RGB(0, 255-(255*(temp++)/(ccChain+i)->iStrLen), 0));
                                TextOut(hdcMem, (ccChain+i)->x, j-=iFontHeight, &((ccChain+i)->point->ch), 1);
                                (ccChain+i)->point = (ccChain+i)->point->next;
                        }
                        if(ctn)
                                (ccChain+i)->iStopTimes = 0 ;
                        else continue;
                        (ccChain+i)->y += iFontHeight; //�´ο�ʼ��ʾ��y���� Ϊ��ǰ��y������� һ���ַ��ĸ߶�
                        //�����ʼ��ʾ��y�����ȥ ������ʾ�еĳ��ȳ�������Ļ�ĸ߶�
                        if( (ccChain+i)->y-(ccChain+i)->iStrLen*iFontHeight > cyScreen)
                        {
                                free( (ccChain+i)->current );
                                init(ccChain+i, cyScreen, (iFontWidth*3/2)*i);
                        }
                        //�����ͷ Ϊ�������ǰ��Ԫ��,��Ϊ�´ο�ʼ��ʾ��ʱ�� ���൱����������ʾ�еĿ�ͷ��Ӹ�Ԫ��,Ȼ���ڿ�ʼ������ʾ
                        (ccChain+i)->head = (ccChain+i)->head->prev;
                        (ccChain+i)->head->ch = randomChar();
                }

                BitBlt(hdc, 0, 0, cxScreen, cyScreen, hdcMem, 0, 0, SRCCOPY);
                ReleaseDC(hwnd, hdc);
                return 0;

        case WM_RBUTTONDOWN:
                KillTimer (hwnd, ID_TIMER) ;
                return 0;

        case WM_RBUTTONUP:
                SetTimer (hwnd, ID_TIMER, 10, NULL) ;
                return 0;

                //�����ƺ���
        case WM_KEYDOWN:
        case WM_LBUTTONDOWN:
        case WM_DESTROY:
                KillTimer (hwnd, ID_TIMER) ;
                DeleteObject(hBitmap);
                DeleteDC(hdcMem);
                for(i=0; i<iColumnCount; i++)
                {
                        free( (ccChain+i)->current );
                }
                free(ccChain);
                PostQuitMessage (0) ;
                return 0 ;
        }
        return DefWindowProc (hwnd, message, wParam, lParam) ;
}
