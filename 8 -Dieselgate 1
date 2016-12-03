#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LIST_BY_YEAR       0
#define LIST_BY_TYPE       1

#define TYPE_MAX           100
#define SETUP_MAX          100

typedef struct TEngine
 {
   struct TEngine * m_Next;
   int              m_Year;
   char             m_Type  [ TYPE_MAX ];
   int              m_Setup [ SETUP_MAX ];
 } TENGINE;

typedef struct TArchive
 {
   struct TArchive * m_Next;
   TENGINE         * m_Engines;
 } TARCHIVE;

TENGINE * createEngine  ( const char      * type,
                          int               year )
{
   int i;
   TENGINE * res = (TENGINE *) malloc ( sizeof  (*res ) );

   res -> m_Next = NULL;
   res -> m_Year = year;
   strncpy ( res -> m_Type, type, sizeof ( res -> m_Type ) );
   for ( i = 0; i < SETUP_MAX; i ++ )
    res -> m_Setup[i] = 0;
   return res;
}


#endif /* __PROGTEST__ */

/*---------------------------------------------------------------------------------------------------*/

void DelEngines(TENGINE *list)
{
   if(list->m_Next) DelEngines(list->m_Next);
   free(list);
}

/*---------------------------------------------------------------------------------------------------*/

/*allocates one TARCHIVE, in which m_next is next, returns pointer to the new allocated TARCHIVE, m_engines is set to NULL */
TARCHIVE *TarchiveAlloc(TARCHIVE *next)
{
   TARCHIVE *tmp = next;
   next = (TARCHIVE*)malloc(sizeof(TARCHIVE));
   next->m_Next = tmp;
   next->m_Engines = NULL;
   return next;
}

/*---------------------------------------------------------------------------------------------------*/

TENGINE *AddToEnginesByType(TENGINE *list, TENGINE *engine)
{
   TENGINE *tmpList = list, *prevNext;

   /*if engine has to go to the beginning of the list*/
   if (strcmp(list->m_Type, engine->m_Type) > 0)
   {
      engine->m_Next = list;
      return engine;
   }

   /*go thru list until reaches engine with bigger type, if finds one puts the engine in front of it*/
   do
   {
      if (strcmp(list->m_Type, engine->m_Type) > 0)
      {
         prevNext->m_Next = engine;
         engine->m_Next = list;
         return tmpList;
      }
      prevNext = list;
      list = list->m_Next;
   }while(list);

   /*when same type is not found, engine is added to the end of list*/
   prevNext->m_Next = engine;
   return tmpList;
}

/*---------------------------------------------------------------------------------------------------*/

TENGINE *AddToEnginesByYear(TENGINE *list, TENGINE *engine)
{
   TENGINE *tmpList = list, *prevNext;

   /*if engine has to go to the beginning of the list*/
   if (list->m_Year > engine->m_Year)
   {
      engine->m_Next = list;
      return engine;
   }

   /*go thru list until reaches engine with bigger type, if finds one puts the engine in front of it*/
   do
   {
      if (list->m_Year > engine->m_Year)
      {
         prevNext->m_Next = engine;
         engine->m_Next = list;
         return tmpList;
      }
      prevNext = list;
      list = list->m_Next;
   }while(list);

   /*when same type is not found, engine is added to the end of list*/
   prevNext->m_Next = engine;
   return tmpList;
}

/*---------------------------------------------------------------------------------------------------*/

TARCHIVE *AddByType(TARCHIVE *list, TENGINE *engine)
{
   TARCHIVE *prevNext, *tmpList = list;

   if (list == NULL)
   {
      list = TarchiveAlloc(NULL);
      list->m_Engines = engine;
      return list;
   }

   /*when type of the first tarchive is already bigger then engine's*/
   if (strcmp(list->m_Engines->m_Type, engine->m_Type) > 0)
   {
      tmpList = TarchiveAlloc(list);
      tmpList->m_Engines = engine;
      return tmpList;
   }

   /*search for tarchive with same type as engine, if find one with bigger type, allocates new tarchive, and puts engine into it*/
   do
   {
      if (strcmp(list->m_Engines->m_Type, engine->m_Type) == 0)
      {
            list->m_Engines = AddToEnginesByYear(list->m_Engines, engine);  
            return tmpList;
      }
      if (strcmp(list->m_Engines->m_Type, engine->m_Type) > 0)
      {
         prevNext->m_Next = TarchiveAlloc(list);
         prevNext->m_Next->m_Engines = engine;
         return tmpList;
      }
      prevNext = list;
      list = list->m_Next;
   } while(list);

   /*when no tarchive with same type is found, new tarchive is added to the end of archive and engine put there*/
   prevNext->m_Next = TarchiveAlloc(NULL);
   prevNext->m_Next->m_Engines = engine;
   return tmpList;
}

/*---------------------------------------------------------------------------------------------------*/


TARCHIVE *AddByYear(TARCHIVE *list, TENGINE *engine)
{
   TARCHIVE *prevNext, *tmpList = list;

   if (list == NULL)
   {
      list = TarchiveAlloc(NULL);
      list->m_Engines = engine;
      return list;
   }

   /*when the first year of the first tarchive is already bigger then engine's*/
   if (list->m_Engines->m_Year > engine->m_Year)
   {
      tmpList = TarchiveAlloc(list);
      tmpList->m_Engines = engine;
      return tmpList;
   }

   /*search for tarchive with same year as engine, if find one with bigger year, allocates new tarchive, and puts engine into it*/
   do
   {
      if (list->m_Engines->m_Year == engine->m_Year)
      {
            list->m_Engines = AddToEnginesByType(list->m_Engines, engine);  
            return tmpList;
      }
      if (list->m_Engines->m_Year > engine->m_Year)
      {
         prevNext->m_Next = TarchiveAlloc(list);
         prevNext->m_Next->m_Engines = engine;
         return tmpList;
      }
      prevNext = list;
      list = list->m_Next;
   } while(list);

   /*when no tarchive with same year is found, new tarchive is added to the end of archive and engine put there*/
   prevNext->m_Next = TarchiveAlloc(NULL);
   prevNext->m_Next->m_Engines = engine;
   return tmpList;
}

/*---------------------------------------------------------------------------------------------------*/

TARCHIVE         * AddEngine                               ( TARCHIVE        * list,
                                                             int               listBy,
                                                             TENGINE         * engine )
   {
       return listBy ? AddByType(list, engine) : AddByYear(list, engine);
   }

/*---------------------------------------------------------------------------------------------------*/

void               DelArchive                              ( TARCHIVE        * list )
   {
      if(list == NULL)
         return;
      if(list->m_Next) DelArchive(list->m_Next);
      DelEngines(list->m_Engines);
      free(list);
   }

/*---------------------------------------------------------------------------------------------------*/

TARCHIVE         * ReorderArchive                          ( TARCHIVE        * list,
                                                             int               listBy )
{
    /*alokace*/
    TARCHIVE *NewArchive = NULL, *tmpArch;
    TENGINE *Engine, *engineTmp;

    if (list == NULL)
       return list;

    /*prohazeni + uvolovani puvodniho archivu*/
    do {
        Engine = list->m_Engines;
        do {

            NewArchive = AddEngine(NewArchive, listBy, Engine);
            engineTmp = Engine->m_Next;
            Engine->m_Next = NULL;
            Engine = engineTmp;
        } while (Engine);

        tmpArch = list->m_Next;
        free(list);
        list = tmpArch;
    } while (list);

    return NewArchive;
}

/*---------------------------------------------------------------------------------------------------*/

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   TARCHIVE * a;

   a = NULL;
   

   ReorderArchive(a, LIST_BY_TYPE);


   return 0;
 }
#endif /* __PROGTEST__ */
