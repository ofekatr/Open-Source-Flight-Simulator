cmake_minimum_required(VERSION 3.12)
project(Project)

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

add_executable(Project main.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h CommandExpression.cpp CommandExpression.h Expression.h DefineVarCommand.cpp DefineVarCommand.h ConnectCommand.cpp ConnectCommand.h Number.cpp Number.h BinaryExpression.h Div.cpp Div.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Parser.cpp Parser.h whileCommand.cpp whileCommand.h ifCommand.cpp ifCommand.h printCommand.cpp printCommand.h ShuntingYard.cpp ShuntingYard.h DataReaderServer.cpp DataReaderServer.h ClientServer.cpp ClientServer.h conditionParser.cpp conditionParser.h Sleep.cpp Sleep.h lexer.cpp lexer.h extractExpression.cpp extractExpression.h dictionaryPath.h SymbolTable.h BIndingTable.h expressionList.h CommandenterC.cpp CommandenterC.h socketSingelton.h)