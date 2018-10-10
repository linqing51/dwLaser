/*  
 * ARM Limited - October 1999 - Defect 33957 workaround.
 *
 * Thumb-ARM Interworking Image emptyarm.c for ARM subtargets.	
 *
 * This source file is a workaround for the fact that Codewarrior does not cope well with empty subtargets.
 *
 * Empty subtargets could occur when Thumb ARM Interworking Image stationery was used for Thumb only interworking
 * with source files only present in ThumbDebugRel, ThumbDebug and ThumbRelease targets.
 *
 * Without this file in the ARM subtargets a fatal link error L6015U occurred. The error was because the ARM subtarget partial
 * link was invoked with no files to link. 
 * A secondary error could occur because no output is produced from an empty ARM subtarget, but the
 * Thumb main target link expected a partially linked subtarget output.
 * (Defect 33957), 
 *
 * NOTE: August 2001.
 *     From ADS1.2 subtargets are no longer partially linked. Selecting Output Type as Directory of objects
 *     in the new ARM Target panel for a subtarget causes the chosen linker to be bypassed and a Target Directory Via file to be produced.
 *     All of  a subtarget's objects can then be added directly to a main target by chaining. This was needed to enable
 *     Scatterloading in Interworking projects, since the scatter file placement is controlled by object file naming.
 *     (Defect 45143)
 * 
 * This file intentionally compiles to an object with no Code or Data.
 * Since there are no functions or variables for the linker to reference, this file will have no effect 
 * on the final image produced (except for a little extra debug information 640 bytes).
 *
 * The C compiler however will give a warning (error when strict ANSI conforming)
 * 		Warning : C3040E: no external declaration in translation unit
 * 		emptyarm.c line 40
 *
 * Normally, you should replace this file with source containing functions which you have to chosen to compile for ARM 
 * because ARM code will run faster from 32 bit memory or because the source uses inline ARM assembler instructions. 
 * Use File->Save As to replace this file in the project.
 *
 * If you do not intend to use ARM code, consider instead creating a project based on the Thumb Executable Image
 * stationery. Only Thumb functions which will be called from ARM (or vice-versa) need to be compiled for interworking.
 * 
 * You can suppress the warning C3040E by editing the target settings (Alt+F7) for ARMDebugRel, ARMDebug and ARMRelease
 * targets.
 * Find ARM C Compiler Targets Settings Panel in Language Settings tree and select No Warnings (-W) on the Warnings page
 * of the ARM C Compiler.
 * Beware that ALL WARNINGS ARE THEN SUPPRESSED FOR ALL ARM SOURCE FILES you add to these targets.
 * You can prevent the strict ANSI error by providing ARM function and variable declarations.
 */
 