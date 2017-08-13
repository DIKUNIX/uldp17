;; settings for all programming modes
(add-hook 'prog-mode-hook (lambda ()
                            (highlight-numbers-mode)
                            (column-number-mode)))
