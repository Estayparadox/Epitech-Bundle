package com.example.josephpereniguez.todolist.db;

/**
 * Created by josephpereniguez on 16/12/2017.
 */

import android.provider.BaseColumns;

/**
 * Data Class
 */
public class TaskContract { // Define constants which used to access the data in the database.
    public static final String DB_NAME = "com.example.josephpereniguez.todolist.db";
    public static final int DB_VERSION = 1;

    /**
     * Data structure class
     */
    public class TaskEntry implements BaseColumns {
        public static final String TABLE = "tasks";

        public static final String COL_TASK_TITLE = "title";
    }
}
