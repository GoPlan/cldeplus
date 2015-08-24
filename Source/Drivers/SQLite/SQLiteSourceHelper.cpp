//
// Created by LE, Duc Anh on 6/17/15.
//

#include "SQLiteSourceHelper.h"


std::string Cloude::Drivers::SQLite::SQLiteSourceHelper::CopyToString(int resultCode) {

    std::string code = std::to_string(resultCode);
    std::string msg{"[RESULTCODE:" + code + "] "};

    switch (resultCode) {

        case SQLITE_OK:
            msg += "The SQLITE_OK result code means that the operation was successful and that there were no errors. " \
            "Most other result codes indicate an error.";
            break;
        case SQLITE_ROW:
            msg += "The SQLITE_ROW result code returned by sqlite3_step() " \
            "indicates that another row of output is available.";
            break;
        case SQLITE_DONE:
            msg += "The SQLITE_DONE result code indicates that an operation has completed. " \
            "The SQLITE_DONE result code is most commonly seen as a return value from sqlite3_step() indicating " \
            "that the SQL statement has run to completion. " \
            "But SQLITE_DONE can also be returned by other multi-step interfaces such as sqlite3_backup_step().";
            break;
        case SQLITE_ERROR:
            msg += "The SQLITE_ERROR result code is a generic error code that is used " \
            "when no other more specific error code is available.";
            break;
        case SQLITE_MISUSE:
            msg += "The SQLITE_MISUSE return code might be returned " \
            "if the application uses any SQLite interface in a way that is undefined or unsupported. " \
            "For example, using a prepared statement after that " \
            "prepared statement has been finalized might result in an SQLITE_MISUSE error.\n" \
            "SQLite tries to detect misuse and report the misuse using this result code. " \
            "However, there is no guarantee that the detection of misuse will be successful. " \
            "Misuse detection is probabilistic. Applications should never depend on an SQLITE_MISUSE return value.\n" \
            "If SQLite ever returns SQLITE_MISUSE from any interface, that means " \
            "that the application is incorrectly coded and needs to be fixed. " \
            "Do not ship an application that sometimes returns " \
            "SQLITE_MISUSE from a standard SQLite interface because " \
            "that application contains potentially serious bugs.";
            break;
        case SQLITE_BUSY:
            msg += "The SQLITE_BUSY result code indicates that the database file could not be written " \
            "(or in some cases read) because of concurrent activity by some other database connection, " \
            "usually a database connection in a separate process.\n" \
            "For example, if process A is in the middle of a large write transaction and at the same time " \
            "process B attempts to start a new write transaction, process B will get back an SQLITE_BUSY " \
            "result because SQLite only supports one writer at a time. " \
            "Process B will need to wait for process A to finish its transaction before starting a new transaction. " \
            "The sqlite3_busy_timeout() and sqlite3_busy_handler() interfaces and the busy_timeout " \
            "pragma are available to process B to help it deal with SQLITE_BUSY errors.\n" \
            "\n" \
            "An SQLITE_BUSY error can occur at any point in a transaction: " \
            "when the transaction is first started, during any write or update operations, " \
            "or when the transaction commits. " \
            "To avoid encountering SQLITE_BUSY errors in the middle of a transaction, " \
            "the application can use BEGIN IMMEDIATE instead of just BEGIN to start a transaction. " \
            "The BEGIN IMMEDIATE command might itself return SQLITE_BUSY, but if it succeeds, " \
            "then SQLite guarantees that no subsequent operations on the same database through " \
            "the next COMMIT will return SQLITE_BUSY.\n" \
            "\n" \
            "See also: SQLITE_BUSY_RECOVERY and SQLITE_BUSY_SNAPSHOT.\n" \
            "\n" \
            "The SQLITE_BUSY result code differs from SQLITE_LOCKED in " \
            "that SQLITE_BUSY indicates a conflict with a separate database connection, " \
            "probably in a separate process, whereas SQLITE_LOCKED indicates a conflict within " \
            "the same database connection (or sometimes a database connection with a shared cache).";
            break;
        case SQLITE_CANTOPEN:
            msg += "The SQLITE_CANTOPEN result code indicates that SQLite was unable to open a file. " \
            "The file in question might be a primary database file or on of several temporary disk files.";
        default:
            msg += "This result code is not yet stored in the helper. Please consult SQLite website.";
            break;
    }

    return msg;
}
