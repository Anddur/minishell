# 42'S MINISHELL SUBJECT
<h3> Developed by Mattia Cossu and Andrea Duregon</h3>

<h2>MANDATORY PART</h2>
<br>

**Program name** | <samp>minishell</samp> 
  -----------------|----------
  **Turn in files** | 
  **Makefile** | Yes 
  **Arguments** | 
  **External functs.** | <code>printf</code>, <code>malloc</code>, <code>free</code>, <code>write</code>, <code>open</code>, <code>read</code>, <code>close</code>, <code>fork</code>, <code>wait</code>, <code>waitpid</code>, <code>wait3</code>, <code>wait4</code>, <code>signal</code>, <code>kill</code>, <code>exit</code>, <code>getcwd</code>, <code>chdir</code>, <code>stat</code>, <code>lstat</code>, <code>fstat</code>, <code>execve</code>, <code>dup</code>, <code>dup2</code>, <code>pipe</code>, <code>opendir</code>, <code>readdir</code>, <code>closedir</code>, <code>strerror</code>, <code>errno</code>, 
  **Libft authorized** | Yes 
  **Description** | Write a shell
  
  <br>
  
  Your shell should:
  - Not use more than one global variable, think about it and be ready to explain why you do it.
  - Show a prompt when waiting for a new command
  - Search and launch the right executable (based on the PATH variable or by using relative or absolute path) like in bash
  - It must implement the builtins like in bash:
    - <samp>echo</samp> with option -n
    - <samp>cd</samp> with only a relative or absolute path
    - <samp>pwd</samp> without any options
    - <samp>export</samp> without any options
    - <samp>unset</samp> without any options
    - <samp>env</samp> without any options and any arguments
    - <samp>exit</samp> without any options
  - <samp>;</samp> in the command should separate commands like in bash
  - <samp>’</samp> and <samp>"</samp> should work like in bash except for multiline commands
  - Redirections <samp><</samp> <samp>></samp> “<samp>>></samp>” should work like in bash except for file descriptor aggregation
  - Pipes <samp>|</samp> should work like in bash except for multiline commands
  - Environment variables (<samp>$</samp> followed by characters) should work like in bash
  - <samp>$?</samp> should work like in bash
  - <samp>ctrl-C</samp>, <samp>ctrl-D</samp> and <samp>ctrl-\</samp> should have the same result as in bash
  - Use up and down arrows to navigate through the command history which we will then be able to edit (at least like we can for classic lines) if we feel like it (the line, not the history).

<br>
<h2>BONUS PART</h2>
<br>

- If the Mandatory part is not perfect don’t even think about bonuses
- You don’t need to do all the bonuses
- Redirection “<samp><<</samp>” like in bash
- Advance history and line editing with Termcaps (man <code>tgetent</code> for examples)
  - Edit the line where the cursor is located.
  - Move the cursor left and right to be able to edit the line at a specific location. Obviously new characters have to be inserted between the existing ones similarly to a classic shell.
  - Cut, copy, and/or paste all or part of a line using the key sequence you prefer.
  - Move directly by word towards the left or the right using <samp>ctrl+LEFT</samp> and <samp>ctrl+RIGHT</samp>.
  - Go directly to the beginning or the end of a line by pressing <samp>home</samp> and <samp>end</samp>.
  - Write AND edit a command over a few lines. In that case, we would love that <samp>ctrl+UP</samp> and <samp>ctrl+DOWN</samp> allow to go from one line to another in the command while remaining in the same column or otherwise the most appropriate column.
- <samp>&&</samp>, <samp>||</samp> with parenthesis for priorities, like in bash
- wilcard <samp>*</samp> like in bash
