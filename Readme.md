# Microlog

a small logger for C++


## example of use
example:
```
logger << microlog::LogLevel::Info << "HelloWorld" << std::endl;

logger << "HelloWorld again!" << std::endl;

for(std::size_t i = 0; i < 16; i++)
{
	logger << "message ";
}

logger << microlog::LogLevel::Warning << "Warning";

logger << microlog::LogLevel::Error << "Error!";

logger << microlog::LogLevel::Debug << "Debug!";

logger << microlog::LogLevel::Fatal << "Fatal Error!";
```

output:

```

[Info] HelloWorld
[Info] HelloWorld again!
[Info] message message message message message message message message message message message message message message message message 
[Warning] Warning
[Error] Error!
[Debug] Debug!
[Fatal] Fatal Error!
```
