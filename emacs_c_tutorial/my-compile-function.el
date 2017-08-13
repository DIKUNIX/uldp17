(defun my-compile-function ()
  "Define custom compile settings relative to active `major-mode`."
  (interactive)
  (defvar filename)
  (defvar comp-flags)
  (defvar output)

  (setq filename (file-name-nondirectory buffer-file-name))

  ;; c-mode
  (when (member major-mode '(c-mode))
    (setq comp-flags "-std=gnu11 -Wall -Werror -pedantic ")
    (setq output (concat "-o " (file-name-sans-extension filename) " "))
    (setq compile-command (concat "gcc " comp-flags output filename)))

  ;; ... other programming modes might be included here ...

  ;; COMPILE:
  (call-interactively 'compile)
  )

(global-set-key (kbd "<f5>") 'my-compile-function)
