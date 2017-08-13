(defun my-c-mode-hook ()
  (setq-default c-basic-offset 2
                tab-width 2
                indent-tabs-mode nil)
  (c-set-offset 'defun-block-intro 2)
  (c-set-offset 'statement-block-intro 2)
  (c-set-offset 'comment-intro 0)
  (c-set-offset 'func-decl-cont 0)
  )

(add-hook 'c-mode-hook 'my-c-mode-hook)
