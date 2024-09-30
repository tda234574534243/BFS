#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// khoi tao GRAPH
struct GRAPH{
	int sodinh;
	int a[MAX][MAX];
};
// Nhap vao ma tran
void NhapMaTran(GRAPH& g){
	cin >> g.sodinh;
	for (int i = 0; i < g.sodinh; i++){
		for (int j = 0; j < g.sodinh; j++){
			cin >> g.a[i][j]; 
		}
	}
}
// Ham kiem tra co phai la ma tran ke khong
bool KiemTraMaTranKeHopLe(GRAPH& g){
	for (int i = 0; i < g.sodinh; i++){
		if (g.a[i][i] != 0){
			return 0;
			break;
		}
	}
	return 1;
}
// Ham kiem tra co phai la ma tran doi xung khong
bool KiemTraDoThiDoiXung(GRAPH& g){
	for (int i = 0; i < g.sodinh; i++){
		for (int j = 0; j < g.sodinh; j++){
			if (g.a[i][j] != g.a[j][i]){
				return 0;
				break;
			}
		}
	}
	return 1;
}
//Xac dinh so canh cua do thi vo huong
int SoCanhVoHuong(GRAPH &g){
	int count = 0;
	for (int i = 0; i < g.sodinh; i++){
		for (int j = i + 1; j < g.sodinh; j++){
			if(g.a[i][j] != 0){
				count++;
			}
		}
	}
	
	return count;
}
//Xac dinh so canh cua do thi co huong
int SoCanhCoHuong(GRAPH& g){
	int count = 0;
	for (int i = 0;i < g.sodinh; i++){
		for (int j = 0;j < g.sodinh; j++){
			if(g.a[i][j] != 0){
				count++;
			}
		}
	}
	return count;
}
// Xac dinh bac cua dinh va tim ra bac lon nhat va nho nhat cua dinh
void BacCuaDinhVoHuong(GRAPH g){
    int max = 0;
    int min = 100000; 
    int posmax = 0;
    int posmin = 0;

    for (int i = 0; i < g.sodinh; i++){
        int count = 0;
        for (int j = 0; j < g.sodinh; j++){
            count += g.a[i][j];
            if (i == j) {  
                count += g.a[i][j];
            }
        }
        cout << "Bac cua dinh " << i << " la: " << count << endl;
        if (count > max){
            max = count;
            posmax = i;
        }
        if (count < min){
            min = count;
            posmin = i;
        }
    }
    
    cout << "Bac lon nhat la dinh: " << posmax << ", Bac: " << max << endl;
    cout << "Bac be nhat la dinh: " << posmin << ", Bac: " << min << endl;
    cout << endl;
    for (int i = 0; i < g.sodinh; i++){
        int count = 0;
        for (int j = 0; j < g.sodinh; j++){
            count += g.a[i][j];
            if (i == j) {  
                count += g.a[i][j];
            }
        }
        if (count % 2 == 0){
        	cout << "Dinh bac chan la dinh " << i << ", Bac: " << count << endl;
		}
    }
    for (int i = 0; i < g.sodinh; i++){
        int count = 0;
        for (int j = 0; j < g.sodinh; j++){
            count += g.a[i][j];
            if (i == j) {  
                count += g.a[i][j];
            }
        }
        if (count % 2 != 0){
        	cout << "Dinh bac le la dinh " << i << ", Bac: " << count << endl;
		}
    }
}
// Tim bac cua dinh co huong va tim ra bac lon nhat va nho nhat cua dinh
void BacCuaDinhCoHuong(GRAPH g){
	int max = 0;
    int min = 100000; 
    int posmax = 0;
    int posmin = 0;
	for (int i = 0; i < g.sodinh; i++){
		int bacvao = 0;
		int bacra = 0;
		for (int j = 0; j < g.sodinh; j++){
			bacvao += g.a[j][i];
		}
		for (int j = 0; j < g.sodinh; j++){
			bacra += g.a[i][j];
		}
		
		int tongbac = bacvao + bacra;
		if (tongbac > max){
			max = tongbac;
			posmax = i;
		}
		if (tongbac < min){
			min = tongbac;
			posmin = i;
		}
		cout << "Bac cua dinh " << i << ": Bac vao = " << bacvao << ", Bac ra = " << bacra << endl;
	}
	cout << "Bac dinh lon nhat la dinh: " << posmax << ", Bac: " << max << endl;
	cout << "Bac dinh be nhat la dinh: " << posmin << ", Bac: " << min << endl;
	cout << endl;
	for (int i = 0; i < g.sodinh; i++){
		int bacvao = 0;
		int bacra = 0;
		for (int j = 0; j < g.sodinh; j++){
			bacvao += g.a[j][i];
		}
		for (int j = 0; j < g.sodinh; j++){
			bacra += g.a[i][j];
		}
		int tongbac = bacvao + bacra;
		if (tongbac % 2 == 0){
			cout << "Dinh bac chan la dinh " << i << ", Bac:" << tongbac << endl;
		}
	}
	for (int i = 0; i < g.sodinh; i++){
		int bacvao = 0;
		int bacra = 0;
		for (int j = 0; j < g.sodinh; j++){
			bacvao += g.a[j][i];
		}
		for (int j = 0; j < g.sodinh; j++){
			bacra += g.a[i][j];
		}
		int tongbac = bacvao + bacra;
		if (tongbac % 2 != 0){
			cout << "Dinh bac le la dinh " << i << ", Bac:" << tongbac << endl;
		}
	}
}
void CheckDinhVoHuong(GRAPH& g){
	for (int i = 0; i < g.sodinh; i++){
        int count = 0;
        for (int j = 0; j < g.sodinh; j++){
            count += g.a[i][j];
            if (i == j) {  
                count += g.a[i][j];
            }
        }
        if (count == 1){
        	cout << "Dinh " << i << " la dinh treo" << endl;
		}
		else if (count == 0){
			cout << "Dinh " << i << " la dinh co lap" << endl;
		}
    }
}
void CheckDinhCoHuong(GRAPH& g){
	for (int i = 0; i < g.sodinh; i++){
		int bacvao = 0;
		int bacra = 0;
		for (int j = 0; j < g.sodinh; j++){
			bacvao += g.a[j][i];
		}
		for (int j = 0; j < g.sodinh; j++){
			bacra += g.a[i][j];
		}
		int tongbac = bacvao + bacra;
		if (tongbac == 0){
			cout << "Dinh " << i << " la dinh co lap" << endl;
		}
		else if (tongbac == 1){
			cout << "Dinh " << i << " la dinh treo" << endl;
		}
	}
}
// Xuat ma tran
void KetQuaMaTran(GRAPH g){
	for (int i = 0; i < g.sodinh; i++){
		for (int j = 0; j < g.sodinh; j++){
			cout << g.a[i][j] << " ";
		}
		cout << endl;
	}
}
// Ham BFS
void BFS(GRAPH& g, int start) {
    bool visited[MAX] = {false};  // Mang danh dau cac dinh da duoc tham
    queue<int> q;  // Hang doi BFS

    // Khoi tao
    visited[start] = true;
    q.push(start);

    cout << "Thu tu duyet BFS bat dau tu dinh " << start << ": ";

    // Lap cho den khi hang doi rong
    while (!q.empty()) {
        int u = q.front();  // Lay dinh o dau hang doi
        q.pop();

        cout << u << " ";  // In dinh hien tai

        // Duyet cac dinh ke cua dinh hien tai
        for (int v = 0; v < g.sodinh; v++) {
            if (g.a[u][v] != 0 && !visited[v]) {  // Neu co canh va dinh chua duoc tham
                visited[v] = true;
                q.push(v);  // Dua dinh v vao hang doi
            }
        }
    }
    cout << endl;
}
int main(){
	GRAPH g; // khoi tao do thi 
	
	NhapMaTran(g); 
	
	if (!KiemTraMaTranKeHopLe(g)){
		cout << "Ma tran khong hop le!" << endl;
	}
	else {
		cout << "Ma tran hop le" << endl;
	}
	
	if (!KiemTraDoThiDoiXung(g)){
		cout << "Do thi khong doi xung!" << endl;
		cout << "=> Do thi co huong" << endl;
		cout << endl;
		cout << "So dinh cua do thi: " << g.sodinh << endl;
		cout << "So canh cua do thi co huong la: " << SoCanhCoHuong(g) << endl;
		cout << endl;
		BacCuaDinhCoHuong(g);
		cout << endl;
		CheckDinhCoHuong(g);
		cout << endl;
	}
	else {
		cout << "Do thi doi xung" << endl;
		cout << "=> Do thi vo huong" << endl;
		cout << endl;
		cout << "So dinh cua do thi: " << g.sodinh << endl;
		cout << "So canh cua do thi vo huong la: "<< SoCanhVoHuong(g) << endl;
		cout << endl;
		BacCuaDinhVoHuong(g);
		cout << endl;
		CheckDinhVoHuong(g);
		cout << endl;
	}
	
	KetQuaMaTran(g);
	int start;
    cout << "Nhap dinh bat dau duyet BFS: ";
    cin >> start;
    BFS(g, start);
	return 0;
}
