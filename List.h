/*
ListCellStructにメンバを追加
newListCellの.cと.hを共に編集
showを編集
*/

#ifndef _LIST_H_
#define _LIST_H_

struct ListCellStruct {
    void* data;
    struct ListCellStruct* next;
};
typedef struct ListCellStruct ListCell;
// dataの先頭アドレスと、サイズを渡す
ListCell* newListCell(size_t dataSize, void* data);
void deleteListCell(ListCell* this);
void ListCell_show(ListCell* this);
// thisが小さければ-1, 大きければ1、同じなら0
int ListCell_Compare(ListCell* this, ListCell* listCell2);


typedef struct {
    ListCell* first;
    ListCell* last;

    // cellのデータ１つあたりのサイズ
    int dataSize;
    void (*showCellData)(void*);

    int length; //がんばって計算してるので代入禁止
} List;
// 末尾に追加
void List_append(List* this, void* data);
// 特定の位置を削除
void List_remove(List* this, int index);
// 特定の位置に挿入
void List_insert(List* this, int index, void* data);
// すべて表示
void List_show(List* this);
// 長さを取得
int List_getLength(List* this);
// 特定の要素をget
void* List_get(List* this, int index);
// 特定の要素をset
void List_set(List* this, int index, void* data);
// リストをすべてクリア
void List_clear(List* this);
// map、変換関数を渡す(セットまで行ってもらう)
void List_map(List* this, void (*mapFunc)(void*));
// リストを連結
void List_extend(List* this, List* list2);
// コンストラクタ、デストラクタ(要素も全て破棄)
List* newList(size_t dataSize, void (*showCellData)(void*));
void deleteList(List* this);

#endif
