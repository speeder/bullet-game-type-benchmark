-- A solution contains projects, and defines the available configurations
solution("BulletTypeBenchmark");
configurations("Release");
platforms({"x32", "x64"});
 
-- A project defines one build target
project("BulletTypeBenchmark");
kind("ConsoleApp");
language("C");
files({ "**.h", "**.c" });

configuration("x32");
defines({ "NDEBUG" });
flags({ "Optimize", "ExtraWarnings" });
targetprefix("32bit");

configuration("x64");
defines({ "NDEBUG" });
flags({ "Optimize", "ExtraWarnings" });
targetprefix("64bit");